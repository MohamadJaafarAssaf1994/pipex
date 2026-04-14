/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_shared.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohassaf <mohassaf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/11 13:31:58 by mohassaf          #+#    #+#             */
/*   Updated: 2026/04/12 09:47:02 by mohassaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_SHARED_H
# define PIPEX_SHARED_H

# include "libft/libft.h"
# include <fcntl.h>
# include <stdio.h>
# include <sys/wait.h>
# include <unistd.h>

typedef struct s_comargs
{
	char	**args;
	char	*command;
	int		exit_status;
}			t_comargs;

void		close_fds(int fd1, int fd2);
void		exec_command_or_exit(char *input, char **env);
char		**get_args(char *str);
void		print_args(char **args);
int			contain_slash(char *str);
int			ft_wordcount(char const *s, char c);
int			is_str_in_tab(char *str, char *str_env);
char		*get_path_env_str(char **env);
char		**get_path_env_tab(char **env);
char		*get_valid_command(char **args, char **path_env_tab);
void		free_tab(char **tab);
char		*get_valid_command_2(char *input);
int			skip_spaces(char *s, int i);
int			escaped_char_len(char *s, int i, char quote);
int			handle_special_char(char *s, int *i, char *quote);
int			token_end(char *s, int start);
int			count_args(char *str);
int			subword_len(char *s, int start);
char		*subword(char *s, int start);
char		**tab_env(char *s);

#endif
