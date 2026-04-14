/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus_children.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohassaf <mohassaf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/12 15:23:35 by mohassaf          #+#    #+#             */
/*   Updated: 2026/04/13 11:47:26 by mohassaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

static int	open_infile_bonus(t_pipex_bonus *px_bonus, char *path)
{
	px_bonus->infile_fd = open(path, O_RDONLY);
	if (px_bonus->infile_fd < 0)
	{
		perror("infile");
		close_fds_bonus(px_bonus->fd, px_bonus->ch);
		return (1);
	}
	return (0);
}

int	open_outfile_bonus(t_pipex_bonus *px_bonus, char *path, int flags)
{
	px_bonus->outfile_fd = open(path, flags, 0644);
	if (px_bonus->outfile_fd < 0)
	{
		perror("outfile");
		close_fds_bonus(px_bonus->fd, px_bonus->ch);
		return (1);
	}
	return (0);
}

void	child_exec_first_child(t_pipex_bonus *px_bonus, char *argv[],
		char *env[])
{
	if (open_infile_bonus(px_bonus, argv[1]) == 1)
	{
		free_pipex_bonus(px_bonus);
		exit(1);
	}
	close(px_bonus->fd[0][0]);
	if (dup2(px_bonus->infile_fd, STDIN_FILENO) == -1)
	{
		perror("dup2 infile");
		close_fds(px_bonus->infile_fd, px_bonus->fd[0][1]);
		free_pipex_bonus(px_bonus);
		exit(1);
	}
	if (dup2(px_bonus->fd[0][1], STDOUT_FILENO) == -1)
	{
		perror("dup2 pipe write");
		close_fds(px_bonus->infile_fd, px_bonus->fd[0][1]);
		free_pipex_bonus(px_bonus);
		exit(1);
	}
	close(px_bonus->infile_fd);
	close_fds_bonus(px_bonus->fd, px_bonus->ch);
	free_pipex_bonus(px_bonus);
	exec_command_or_exit(argv[2], env);
}

void	child_exec_child_i(t_pipex_bonus *px_bonus, char *argv[], char *env[],
		int i)
{
	if (dup2(px_bonus->fd[i - 1][0], STDIN_FILENO) == -1)
	{
		perror("dup2 pipe read");
		close_fds_bonus(px_bonus->fd, px_bonus->ch);
		free_pipex_bonus(px_bonus);
		exit(1);
	}
	if (dup2(px_bonus->fd[i][1], STDOUT_FILENO) == -1)
	{
		perror("dup2 pipe write");
		close_fds_bonus(px_bonus->fd, px_bonus->ch);
		free_pipex_bonus(px_bonus);
		exit(1);
	}
	close_fds_bonus(px_bonus->fd, px_bonus->ch);
	free_pipex_bonus(px_bonus);
	exec_command_or_exit(argv[i + 2], env);
}

void	child_exec_last_child(t_pipex_bonus *px_bonus, char *argv[],
		char *env[])
{
	if (open_outfile_bonus(px_bonus, argv[px_bonus->ch + 2],
			O_WRONLY | O_CREAT | O_TRUNC) == 1)
	{
		free_pipex_bonus(px_bonus);
		exit(1);
	}
	close(px_bonus->fd[px_bonus->ch - 2][1]);
	if (dup2(px_bonus->fd[px_bonus->ch - 2][0], STDIN_FILENO) == -1)
	{
		perror("dup2 pipe read");
		close_fds(px_bonus->fd[px_bonus->ch - 2][0], px_bonus->outfile_fd);
		free_pipex_bonus(px_bonus);
		exit(1);
	}
	if (dup2(px_bonus->outfile_fd, STDOUT_FILENO) == -1)
	{
		perror("dup2 outfile");
		close_fds(px_bonus->fd[px_bonus->ch - 2][0], px_bonus->outfile_fd);
		free_pipex_bonus(px_bonus);
		exit(1);
	}
	close(px_bonus->outfile_fd);
	close_fds_bonus(px_bonus->fd, px_bonus->ch);
	free_pipex_bonus(px_bonus);
	exec_command_or_exit(argv[px_bonus->ch + 1], env);
}
