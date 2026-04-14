/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohassaf <mohassaf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/27 14:45:26 by mohassaf          #+#    #+#             */
/*   Updated: 2026/04/13 18:01:38 by mohassaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static int	is_white_space(char c)
{
	if (c == 32 || (c >= 9 && c <= 13))
		return (1);
	return (0);
}

int	skip_spaces(char *s, int i)
{
	while (s[i] && is_white_space(s[i]))
		i++;
	return (i);
}

int	escaped_char_len(char *s, int i, char quote)
{
	if (s[i] != '\\' || !s[i + 1])
		return (0);
	if (quote == '\'')
		return (0);
	if (quote == '"')
	{
		if (s[i + 1] == '"' || s[i + 1] == '\\' || s[i + 1] == '$')
			return (2);
	}
	else
		return (2);
	return (0);
}

int	handle_special_char(char *s, int *i, char *quote)
{
	int	escaped_len;

	escaped_len = escaped_char_len(s, *i, *quote);
	if (escaped_len)
	{
		*i += escaped_len;
		return (escaped_len);
	}
	if ((s[*i] == '\'' || s[*i] == '"') && *quote == 0)
	{
		*quote = s[*i];
		(*i)++;
		return (-1);
	}
	if (s[*i] == *quote)
	{
		*quote = 0;
		(*i)++;
		return (-1);
	}
	return (0);
}

int	token_end(char *s, int start)
{
	int		i;
	char	quote;
	int		special_len;

	i = start;
	quote = 0;
	while (s[i])
	{
		special_len = handle_special_char(s, &i, &quote);
		if (special_len)
			continue ;
		if (quote == 0 && (s[i] == 32 || (s[i] >= 9 && s[i] <= 13)))
			break ;
		i++;
	}
	return (i);
}
