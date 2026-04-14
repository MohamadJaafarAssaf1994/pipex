/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_exec.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohassaf <mohassaf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/23 15:00:00 by mohassaf          #+#    #+#             */
/*   Updated: 2026/04/11 15:05:37 by mohassaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	first_child_exec(t_pipex *px, char **argv, char **env)
{
	px->infile_fd = open(argv[1], O_RDONLY);
	if (px->infile_fd < 0)
	{
		perror("infile");
		close_fds(px->fd[0], px->fd[1]);
		exit(1);
	}
	close(px->fd[0]);
	if (dup2(px->infile_fd, STDIN_FILENO) == -1)
	{
		perror("dup2 infile");
		close_fds(px->infile_fd, px->fd[1]);
		exit(1);
	}
	if (dup2(px->fd[1], STDOUT_FILENO) == -1)
	{
		perror("dup2 pipe write");
		close_fds(px->infile_fd, px->fd[1]);
		exit(1);
	}
	close_fds(px->infile_fd, px->fd[1]);
	exec_command_or_exit(argv[2], env);
}

void	second_child_exec(t_pipex *px, char **argv, char **env)
{
	px->outfile_fd = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (px->outfile_fd < 0)
	{
		perror("outfile");
		close_fds(px->fd[0], px->fd[1]);
		exit(1);
	}
	close(px->fd[1]);
	if (dup2(px->fd[0], STDIN_FILENO) == -1)
	{
		perror("dup2 pipe read");
		close_fds(px->fd[0], px->outfile_fd);
		exit(1);
	}
	if (dup2(px->outfile_fd, STDOUT_FILENO) == -1)
	{
		perror("dup2 outfile");
		close_fds(px->fd[0], px->outfile_fd);
		exit(1);
	}
	close_fds(px->fd[0], px->outfile_fd);
	exec_command_or_exit(argv[3], env);
}

int	parent_wait_and_return(t_pipex *px)
{
	int		status;
	int		i;
	pid_t	ended_pid;

	close_fds(px->fd[0], px->fd[1]);
	i = 0;
	while (i < 2)
	{
		ended_pid = waitpid(-1, &status, 0);
		if (ended_pid == -1)
			return (1);
		if (ended_pid == px->pid2)
			px->status2 = status;
		i++;
	}
	if (WIFEXITED(px->status2))
		return (WEXITSTATUS(px->status2));
	if (WIFSIGNALED(px->status2))
		return (128 + WTERMSIG(px->status2));
	return (1);
}
