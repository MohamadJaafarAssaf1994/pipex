/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohassaf <mohassaf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/10 16:23:50 by mohassaf          #+#    #+#             */
/*   Updated: 2026/04/13 11:55:01 by mohassaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

static int	free_bonus_alloc(t_pipex_bonus *px_bonus, int i)
{
	while (i > 0)
		free(px_bonus->fd[--i]);
	free(px_bonus->fd);
	free(px_bonus->pid);
	return (1);
}

static int	alloc_bonus_pipes(t_pipex_bonus *px_bonus, int ch)
{
	int	i;

	i = 0;
	while (i < ch - 1)
	{
		px_bonus->fd[i] = malloc(2 * sizeof(int));
		if (!px_bonus->fd[i])
			return (free_bonus_alloc(px_bonus, i));
		if (pipe(px_bonus->fd[i]) == -1)
		{
			perror("pipe");
			free(px_bonus->fd[i]);
			return (free_bonus_alloc(px_bonus, i));
		}
		i++;
	}
	return (0);
}

static int	handle_bonus_usage(int argc, char *argv[], char *env[])
{
	if (argc >= 2 && ft_strncmp(argv[1], "here_doc", 9) == 0)
	{
		if (argc < 6)
		{
			ft_putstr_fd("Usage: ./pipex_bonus here_doc LIMITER "
				"cmd1 cmd2 ... file\n", STDERR_FILENO);
			return (1);
		}
		return (run_here_doc_bonus(argc, argv, env));
	}
	if (argc < 5)
	{
		ft_putstr_fd("Usage: ./pipex_bonus file1 cmd1 cmd2 ... file2\n",
			STDERR_FILENO);
		return (1);
	}
	return (0);
}

int	init_pipex_bonus(t_pipex_bonus *px_bonus, int ch)
{
	px_bonus->infile_fd = -1;
	px_bonus->outfile_fd = -1;
	px_bonus->ch = ch;
	px_bonus->pid = malloc(ch * sizeof(pid_t));
	if (!px_bonus->pid)
		return (1);
	px_bonus->fd = malloc((ch - 1) * sizeof(int *));
	if (!px_bonus->fd)
	{
		free(px_bonus->pid);
		return (1);
	}
	return (alloc_bonus_pipes(px_bonus, ch));
}

int	main(int argc, char *argv[], char *env[])
{
	t_pipex_bonus	px_bonus;
	int				status;

	if (argc >= 2 && ft_strncmp(argv[1], "here_doc", 9) == 0)
		return (handle_bonus_usage(argc, argv, env));
	status = handle_bonus_usage(argc, argv, env);
	if (status != 0)
		return (status);
	if (init_pipex_bonus(&px_bonus, argc - 3) == 1)
		return (1);
	status = fork_bonus_children(&px_bonus, argv, env);
	if (status != 0)
		return (status);
	return (parent_wait_and_return_bonus(&px_bonus));
}
