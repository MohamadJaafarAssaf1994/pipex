/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohassaf <mohassaf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 16:46:33 by mohassaf          #+#    #+#             */
/*   Updated: 2026/04/13 18:08:42 by mohassaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static int	init_pipex(t_pipex *px)
{
	px->infile_fd = -1;
	px->outfile_fd = -1;
	px->status2 = 0;
	if (pipe(px->fd) == -1)
	{
		perror("pipe");
		return (1);
	}
	return (0);
}

static int	fork1_failed(t_pipex *px)
{
	perror("Fork1");
	close_fds(px->fd[0], px->fd[1]);
	if (px->infile_fd >= 0)
		close(px->infile_fd);
	if (px->outfile_fd >= 0)
		close(px->outfile_fd);
	return (1);
}

static int	fork2_failed(t_pipex *px)
{
	perror("Fork2");
	close_fds(px->fd[0], px->fd[1]);
	if (px->infile_fd >= 0)
		close(px->infile_fd);
	if (px->outfile_fd >= 0)
		close(px->outfile_fd);
	waitpid(px->pid1, NULL, 0);
	return (1);
}

int	main(int argc, char *argv[], char *env[])
{
	t_pipex	px;

	if (argc != 5)
	{
		ft_putstr_fd("Usage: ./pipex infile cmd1 cmd2 outfile\n",
			STDERR_FILENO);
		return (1);
	}
	if (init_pipex(&px) == 1)
		return (1);
	px.pid1 = fork();
	if (px.pid1 == -1)
		return (fork1_failed(&px));
	if (px.pid1 == 0)
		first_child_exec(&px, argv, env);
	px.pid2 = fork();
	if (px.pid2 == -1)
		return (fork2_failed(&px));
	if (px.pid2 == 0)
		second_child_exec(&px, argv, env);
	return (parent_wait_and_return(&px));
}
