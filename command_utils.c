/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohassaf <mohassaf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/25 15:37:21 by mohassaf          #+#    #+#             */
/*   Updated: 2026/04/03 19:14:10 by mohassaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	ft_wordcount(char const *s, char c)
{
	int	i;
	int	count;
	int	next;

	i = 0;
	count = 0;
	next = 0;
	while (s[i])
	{
		if (s[i] != c && next == 0)
		{
			count++;
			next = 1;
		}
		if (s[i] == c)
			next = 0;
		i++;
	}
	return (count);
}

char	**get_args(char *str)
{
	char	**result;

	if (ft_strlen(str) == 0)
	{
		ft_printf("Empty");
		exit(0);
	}
	if (contain_slash(str))
	{
		result = ft_split(str, '/');
		str = result[ft_wordcount(str, '/') - 1];
	}
	result = ft_split(str, ' ');
	return (result);
}

void	print_args(char **args)
{
	int	i;

	i = 0;
	if (!args)
	{
		printf("args is NULL\n");
		return ;
	}
	while (args[i])
	{
		fprintf(stderr, "args[%d] = [%s]\n", i, args[i]);
		i++;
	}
	fprintf(stderr, "args[%d] = NULL\n", i);
}

int	contain_slash(char *str)
{
	if (ft_strchr(str, '/') != NULL)
		return (1);
	return (0);
}

char	*get_valid_command_2(char *input)
{
	char	**result;
	char	*command;

	result = ft_split(input, ' ');
	command = result[0];
	return (command);
}
