/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohassaf <mohassaf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/10 16:40:17 by mohassaf          #+#    #+#             */
/*   Updated: 2026/04/13 11:47:18 by mohassaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H

# include "libft/getNextLine/get_next_line.h"
# include "pipex_shared.h"

typedef struct s_pipex_bonus
{
	pid_t	*pid;
	int		**fd;
	int		infile_fd;
	int		outfile_fd;
	int		ch;
}			t_pipex_bonus;

int			init_pipex_bonus(t_pipex_bonus *px_bonus, int ch);
void		free_pipex_bonus(t_pipex_bonus *px_bonus);
void		child_exec_i(t_pipex_bonus px_bonus, char *argv[], char *env[],
				int i);
void		close_fds_bonus(int **fd, int ch);
void		child_exec_last_child(t_pipex_bonus *px_bonus, char *argv[],
				char *env[]);
void		child_exec_child_i(t_pipex_bonus *px_bonus, char *argv[],
				char *env[], int pipe_number);
int			fork_failed_bonus(t_pipex_bonus *px_bonus, int created_children);
int			parent_wait_and_return_bonus(t_pipex_bonus *px_bonus);
void		child_exec_first_child(t_pipex_bonus *px_bonus, char *argv[],
				char *env[]);
int			open_outfile_bonus(t_pipex_bonus *px_bonus, char *path, int flags);
void		child_exec_i_here_doc(t_pipex_bonus px_bonus, char *argv[],
				char *env[], int i);
int			run_here_doc_bonus(int argc, char *argv[], char *env[]);
int			fill_here_doc_pipe(char *limiter, int write_fd);
int			is_limiter(char *line, char *limiter);
int			init_here_doc_bonus(t_pipex_bonus *px_bonus, int argc, char *argv[],
				int here_doc_fd[2]);
int			fork_here_doc_children(t_pipex_bonus *px_bonus, char *argv[],
				char *env[], int here_doc_fd);
int			fork_bonus_children(t_pipex_bonus *px_bonus, char *argv[],
				char *env[]);

#endif
