/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohassaf <mohassaf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/15 10:03:05 by mohassaf          #+#    #+#             */
/*   Updated: 2026/02/17 19:08:51 by mohassaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// memcpy copies n bytes from src to dest, one byte at a time.
void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char		*d;
	const unsigned char	*s;

	if (!dest && !src)
		return (NULL);
	d = (unsigned char *)dest;
	s = (const unsigned char *)src;
	while (n--)
		*d++ = *s++;
	return (dest);
}

/*
int	main(void)
{
	int	array[] = {12, 12, 43, 134, 62};
	int	copy[5];
	int	length;

	length = sizeof(int) * 5;
	ft_memcpy(copy, array, length);
	for (length = 0; length < 5; length++)
	{
		printf("%d ", copy[length]);
	}
	printf("\n");
}*/
