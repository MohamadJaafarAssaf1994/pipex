/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohassaf <mohassaf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/15 14:33:41 by mohassaf          #+#    #+#             */
/*   Updated: 2025/11/24 15:02:48 by mohassaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// strlcpy copies a string into a destination buffer,
// ensuring null-termination and never writing more than dstsize bytes.
size_t	ft_strlcpy(char *dest, const char *src, size_t n)
{
	size_t	i;
	size_t	src_len;

	src_len = 0;
	while (src[src_len])
		src_len++;
	if (n == 0)
		return (src_len);
	i = 0;
	while (src[i] && i < n - 1)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (src_len);
}
/*
int	main(void)
{
	char	src[] = "Hello word";
	char	*dest;
	int		i;

	i = ft_strlcpy(dest, src, 3);
	printf("The destination is: %s", dest);
}*/
