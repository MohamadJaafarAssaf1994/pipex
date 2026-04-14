/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohassaf <mohassaf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/16 14:24:41 by mohassaf          #+#    #+#             */
/*   Updated: 2025/11/21 17:49:20 by mohassaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*p1;
	unsigned char	*p2;

	if (n == 0)
		return (0);
	i = 0;
	p1 = (unsigned char *)s1;
	p2 = (unsigned char *)s2;
	while (i < n - 1 && p1[i] == p2[i])
		i++;
	return ((unsigned char)p1[i] - (unsigned char)p2[i]);
}
/*#include <string.h>

int	main(void)
{
	char	s1[] = "Hello world";
	char	s2[] = "Hello";

	printf("%d", memcmp(s1, s2, 9));
}*/
