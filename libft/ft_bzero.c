/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohassaf <mohassaf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 17:21:22 by mohassaf          #+#    #+#             */
/*   Updated: 2025/11/15 11:03:26 by mohassaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*p;

	p = s;
	while (n--)
		*p++ = '\0';
}
/*#include <strings.h>
int	main(void)
{
	char	str1[20] = "Hello my world !";
	char	str2[20] = "Hello my world !";
	int		i;

	bzero(str1, 5);
	ft_bzero(str2, 5);
	i = 0;
	while (i < 20)
		printf("%c ", str1[i++]);
	printf("\n");
	i = 0;
	while (i < 20)
		printf("%c ", str2[i++]);
}*/
