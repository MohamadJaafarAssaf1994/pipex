/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus_runtime.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohassaf <mohassaf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/12 15:23:27 by mohassaf          #+#    #+#             */
/*   Updated: 2026/04/13 11:47:18 by mohassaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	free_pipex_bonus(t_pipex_bonus *px_bonus)
{
	int	i;

	i = 0;
	while (i < px_bonus->ch - 1)
	{
		free(px_bonus->fd[i]);
		i++;
	}
	free(px_bonus->fd);
	free(px_bonus->pid);
}

int	parent_wait_and_return_bonus(t_pipex_bonus *px_bonus)
{
	int		i;
	int		status;
	int		last_status;
	pid_t	ended_pid;

	close_fds_bonus(px_bonus->fd, px_bonus->ch);
	i = -1;
	last_status = 0;
	while (++i < px_bonus->ch)
	{
		ended_pid = waitpid(-1, &status, 0);
		if (ended_pid == -1)
			return (free_pipex_bonus(px_bonus), 1);
		if (ended_pid == px_bonus->pid[px_bonus->ch - 1])
			last_status = status;
	}
	free_pipex_bonus(px_bonus);
	if (WIFEXITED(last_status))
		return (WEXITSTATUS(last_status));
	if (WIFSIGNALED(last_status))
		return (128 + WTERMSIG(last_status));
	return (1);
}

int	fork_failed_bonus(t_pipex_bonus *px_bonus, int created_children)
{
	int	i;

	perror("fork");
	close_fds_bonus(px_bonus->fd, px_bonus->ch);
	i = 0;
	while (i < created_children)
	{
		if (waitpid(px_bonus->pid[i], NULL, 0) == -1)
		{
			free_pipex_bonus(px_bonus);
			return (1);
		}
		i++;
	}
	free_pipex_bonus(px_bonus);
	return (1);
}

void	close_fds_bonus(int **fd, int ch)
{
	int	i;

	i = 0;
	while (i < ch - 1)
	{
		close(fd[i][0]);
		close(fd[i][1]);
		i++;
	}
}

void	child_exec_i(t_pipex_bonus px_bonus, char *argv[], char *env[], int i)
{
	if (i == 0)
		child_exec_first_child(&px_bonus, argv, env);
	else if (i == px_bonus.ch - 1)
		child_exec_last_child(&px_bonus, argv, env);
	else
		child_exec_child_i(&px_bonus, argv, env, i);
}
