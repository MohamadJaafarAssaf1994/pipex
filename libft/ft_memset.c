/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohassaf <mohassaf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 13:30:39 by mohassaf          #+#    #+#             */
/*   Updated: 2025/11/24 15:32:21 by mohassaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//memset fills a block of memory with the same byte value, one byte at a time.
void	*ft_memset(void *str, int c, size_t n)
{
	size_t			i;
	unsigned char	*p;

	i = 0;
	p = (unsigned char *)str;
	while (i < n)
	{
		p[i] = (unsigned char)c;
		i++;
	}
	return (str);
}
/*
int	main(void)
{
	int	array[] = {54, 12, 20, 63, 21, 34};

	ft_memset(array, 0, 4);
	for (int j = 0; j < 6; j++)
	{
		printf("%d ", array[j]);
	}
}*/
