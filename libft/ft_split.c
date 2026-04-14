/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohassaf <mohassaf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 11:05:11 by mohassaf          #+#    #+#             */
/*   Updated: 2026/02/13 16:01:07 by mohassaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_wordcount(char const *s, char c)
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

static char	*ft_subword(char const *s, int start, char c)
{
	int		i;
	int		len;
	char	*word;

	len = 0;
	while (s[start + len] && s[start + len] != c)
		len++;
	word = malloc((len + 1) * sizeof(char));
	if (!word)
		return (NULL);
	i = 0;
	while (i < len)
	{
		word[i] = s[start + i];
		i++;
	}
	word[i] = '\0';
	return (word);
}

static void	*ft_free_all(char **arr, int j)
{
	int	i;

	i = 0;
	while (i < j)
	{
		free(arr[i]);
		i++;
	}
	free(arr);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	int		j;
	char	**result;

	if (!s)
		return (NULL);
	result = malloc((ft_wordcount(s, c) + 1) * sizeof(char *));
	if (!result)
		return (NULL);
	i = 0;
	j = 0;
	while (s[i])
	{
		if (s[i] != c && (i == 0 || s[i - 1] == c))
		{
			result[j] = ft_subword(s, i, c);
			if (!result[j])
				return (ft_free_all(result, j));
			j++;
		}
		i++;
	}
	result[j] = NULL;
	return (result);
}
/*void	print_split(char **tab)
{
	int	i;

	i = 0;
	if (!tab)
	{
		printf("NULL\n");
		return ;
	}
	while (tab[i])
	{
		printf(" [%s] ", tab[i]);
		i++;
	}
	printf("\n");
}

int	main(void)
{
	char	**tab;

	tab = ft_split("hello world test", ' ');
	print_split(tab);
	tab = ft_split("  hello   world   test  ", ' ');
	print_split(tab);
	return (0);
}*/
