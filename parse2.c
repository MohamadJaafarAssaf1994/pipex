/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohassaf <mohassaf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/27 14:45:26 by mohassaf          #+#    #+#             */
/*   Updated: 2026/04/13 16:06:48 by mohassaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	count_args(char *str)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		i = skip_spaces(str, i);
		if (!str[i])
			break ;
		count++;
		i = token_end(str, i);
	}
	return (count);
}

int	subword_len(char *s, int start)
{
	int		i;
	int		len;
	int		end;
	char	quote;
	int		special_len;

	i = start;
	len = 0;
	end = token_end(s, start);
	quote = 0;
	while (s[i] && i < end)
	{
		special_len = handle_special_char(s, &i, &quote);
		if (special_len)
		{
			if (special_len > 0)
				len++;
			continue ;
		}
		len++;
		i++;
	}
	return (len);
}

static char	*alloc_subword(char *s, int start, int *end)
{
	*end = token_end(s, start);
	return (malloc(sizeof(char) * (subword_len(s, start) + 1)));
}

char	*subword(char *s, int start)
{
	char	*word;
	int		i;
	int		j;
	int		end;
	char	quote;

	word = alloc_subword(s, start, &end);
	if (!word)
		return (NULL);
	i = start;
	j = ((quote = 0));
	while (s[i] && i < end)
	{
		if (escaped_char_len(s, i, quote))
		{
			word[j++] = s[i + 1];
			i += escaped_char_len(s, i, quote);
		}
		else if (!handle_special_char(s, &i, &quote))
			word[j++] = s[i++];
	}
	word[j] = '\0';
	return (word);
}

char	**tab_env(char *s)
{
	int		i;
	int		j;
	char	**tab;

	tab = ft_calloc(count_args(s) + 1, sizeof(char *));
	if (!tab)
		return (NULL);
	i = ((j = 0));
	while (s[i])
	{
		i = skip_spaces(s, i);
		if (!s[i])
			break ;
		tab[j] = subword(s, i);
		if (!tab[j])
		{
			free_tab(tab);
			return (NULL);
		}
		i = token_end(s, i);
		j++;
	}
	tab[j] = NULL;
	return (tab);
}
