/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohassaf <mohassaf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/26 12:40:30 by mohassaf          #+#    #+#             */
/*   Updated: 2026/04/03 19:14:10 by mohassaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	is_str_in_tab(char *str, char *str_env)
{
	int		i;
	char	**tab;

	if (!str || !str_env)
		return (0);
	tab = ft_split(str_env, ':');
	i = 0;
	while (tab[i])
	{
		if (ft_strncmp(str, tab[i], 100) == 0)
			return (1);
		i++;
	}
	return (0);
}

char	*get_path_env_str(char **env)
{
	int		i;
	char	*substr;

	i = 0;
	while (env[i])
	{
		substr = ft_substr(env[i], 0, 5);
		if (!substr)
			return (NULL);
		if (ft_strncmp(substr, "PATH=", 5) == 0)
		{
			free(substr);
			return (env[i] + 5);
		}
		free(substr);
		i++;
	}
	return (NULL);
}

char	**get_path_env_tab(char **env)
{
	char	*path_env_str;

	path_env_str = get_path_env_str(env);
	if (!path_env_str)
		return (NULL);
	return (ft_split(path_env_str, ':'));
}

void	free_tab(char **tab)
{
	int	i;

	if (!tab)
		return ;
	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

char	*get_valid_command(char **args, char **path_env_tab)
{
	char	*tmp;
	char	*command;
	int		i;

	i = 0;
	if (!path_env_tab || !args || !args[0])
		return (NULL);
	while (path_env_tab[i])
	{
		tmp = ft_strjoin(path_env_tab[i], "/");
		if (!tmp)
			return (NULL);
		command = ft_strjoin(tmp, args[0]);
		free(tmp);
		if (!command)
			return (NULL);
		if (access(command, X_OK) != -1)
			return (command);
		free(command);
		i++;
	}
	return (NULL);
}
