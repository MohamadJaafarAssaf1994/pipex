/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohassaf <mohassaf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 16:46:36 by mohassaf          #+#    #+#             */
/*   Updated: 2026/04/13 18:08:55 by mohassaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "pipex_shared.h"

typedef struct s_pipex
{
	pid_t	pid1;
	pid_t	pid2;
	int		fd[2];
	int		infile_fd;
	int		outfile_fd;
	int		status2;
}			t_pipex;

void		first_child_exec(t_pipex *px, char **argv, char **env);
void		second_child_exec(t_pipex *px, char **argv, char **env);
int			parent_wait_and_return(t_pipex *px);
#endif
