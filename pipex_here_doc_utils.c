/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_here_doc_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohassaf <mohassaf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/12 14:00:41 by mohassaf          #+#    #+#             */
/*   Updated: 2026/04/13 11:47:18 by mohassaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

int	is_limiter(char *line, char *limiter)
{
	int	len;

	len = ft_strlen(limiter);
	if (ft_strncmp(line, limiter, len) != 0)
		return (0);
	if (line[len] == '\n' && line[len + 1] == '\0')
		return (1);
	if (line[len] == '\0')
		return (1);
	return (0);
}

int	fill_here_doc_pipe(char *limiter, int write_fd)
{
	char	*line;

	while (1)
	{
		line = get_next_line(STDIN_FILENO);
		if (!line)
			break ;
		if (is_limiter(line, limiter))
		{
			free(line);
			break ;
		}
		if (write(write_fd, line, ft_strlen(line)) == -1)
		{
			perror("write");
			free(line);
			return (1);
		}
		free(line);
	}
	get_next_line(-1);
	return (0);
}

int	init_here_doc_bonus(t_pipex_bonus *px_bonus, int argc, char *argv[],
		int here_doc_fd[2])
{
	if (pipe(here_doc_fd) == -1)
		return (perror("pipe"), 1);
	if (fill_here_doc_pipe(argv[2], here_doc_fd[1]) == 1)
	{
		close_fds(here_doc_fd[0], here_doc_fd[1]);
		return (1);
	}
	close(here_doc_fd[1]);
	if (init_pipex_bonus(px_bonus, argc - 4) == 1)
	{
		close(here_doc_fd[0]);
		return (1);
	}
	return (0);
}

int	fork_here_doc_children(t_pipex_bonus *px_bonus, char *argv[], char *env[],
		int here_doc_fd)
{
	int	i;

	i = 0;
	while (i < px_bonus->ch)
	{
		px_bonus->pid[i] = fork();
		if (px_bonus->pid[i] == -1)
		{
			close(here_doc_fd);
			return (fork_failed_bonus(px_bonus, i));
		}
		if (px_bonus->pid[i] == 0)
			child_exec_i_here_doc(*px_bonus, argv, env, i);
		i++;
	}
	return (0);
}

int	fork_bonus_children(t_pipex_bonus *px_bonus, char *argv[], char *env[])
{
	int	i;

	i = 0;
	while (i < px_bonus->ch)
	{
		px_bonus->pid[i] = fork();
		if (px_bonus->pid[i] == -1)
			return (fork_failed_bonus(px_bonus, i));
		if (px_bonus->pid[i] == 0)
			child_exec_i(*px_bonus, argv, env, i);
		i++;
	}
	return (0);
}
