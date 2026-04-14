/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_here_doc.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohassaf <mohassaf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/11 16:24:05 by mohassaf          #+#    #+#             */
/*   Updated: 2026/04/13 11:48:00 by mohassaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

static void	child_exec_first_here_doc(t_pipex_bonus *px_bonus, char *argv[],
		char *env[])
{
	close(px_bonus->fd[0][0]);
	if (dup2(px_bonus->infile_fd, STDIN_FILENO) == -1)
	{
		perror("dup2 here_doc");
		close_fds(px_bonus->infile_fd, px_bonus->fd[0][1]);
		exit(1);
	}
	if (dup2(px_bonus->fd[0][1], STDOUT_FILENO) == -1)
	{
		perror("dup2 pipe write");
		close_fds(px_bonus->infile_fd, px_bonus->fd[0][1]);
		exit(1);
	}
	close(px_bonus->infile_fd);
	close_fds_bonus(px_bonus->fd, px_bonus->ch);
	free_pipex_bonus(px_bonus);
	exec_command_or_exit(argv[3], env);
}

static void	child_exec_middle_here_doc(t_pipex_bonus *px_bonus, char *argv[],
		char *env[], int i)
{
	if (dup2(px_bonus->fd[i - 1][0], STDIN_FILENO) == -1)
	{
		perror("dup2 pipe read");
		close_fds_bonus(px_bonus->fd, px_bonus->ch);
		exit(1);
	}
	if (dup2(px_bonus->fd[i][1], STDOUT_FILENO) == -1)
	{
		perror("dup2 pipe write");
		close_fds_bonus(px_bonus->fd, px_bonus->ch);
		exit(1);
	}
	close_fds_bonus(px_bonus->fd, px_bonus->ch);
	free_pipex_bonus(px_bonus);
	exec_command_or_exit(argv[i + 3], env);
}

static void	child_exec_last_here_doc(t_pipex_bonus *px_bonus, char *argv[],
		char *env[])
{
	if (open_outfile_bonus(px_bonus, argv[px_bonus->ch + 3],
			O_WRONLY | O_CREAT | O_APPEND) == 1)
		exit(1);
	close(px_bonus->fd[px_bonus->ch - 2][1]);
	if (dup2(px_bonus->fd[px_bonus->ch - 2][0], STDIN_FILENO) == -1)
	{
		perror("dup2 pipe read");
		close_fds(px_bonus->fd[px_bonus->ch - 2][0], px_bonus->outfile_fd);
		exit(1);
	}
	if (dup2(px_bonus->outfile_fd, STDOUT_FILENO) == -1)
	{
		perror("dup2 outfile");
		close_fds(px_bonus->fd[px_bonus->ch - 2][0], px_bonus->outfile_fd);
		exit(1);
	}
	close(px_bonus->outfile_fd);
	close_fds_bonus(px_bonus->fd, px_bonus->ch);
	free_pipex_bonus(px_bonus);
	exec_command_or_exit(argv[px_bonus->ch + 2], env);
}

void	child_exec_i_here_doc(t_pipex_bonus px_bonus, char *argv[], char *env[],
		int i)
{
	if (i != 0)
		close(px_bonus.infile_fd);
	if (i == 0)
		child_exec_first_here_doc(&px_bonus, argv, env);
	else if (i == px_bonus.ch - 1)
		child_exec_last_here_doc(&px_bonus, argv, env);
	else
		child_exec_middle_here_doc(&px_bonus, argv, env, i);
}

int	run_here_doc_bonus(int argc, char *argv[], char *env[])
{
	t_pipex_bonus	px_bonus;
	int				here_doc_fd[2];
	int				status;

	if (init_here_doc_bonus(&px_bonus, argc, argv, here_doc_fd) != 0)
		return (1);
	px_bonus.infile_fd = here_doc_fd[0];
	status = fork_here_doc_children(&px_bonus, argv, env, here_doc_fd[0]);
	if (status != 0)
		return (status);
	close(px_bonus.infile_fd);
	return (parent_wait_and_return_bonus(&px_bonus));
}
