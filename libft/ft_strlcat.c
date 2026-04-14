/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohassaf <mohassaf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/16 10:08:53 by mohassaf          #+#    #+#             */
/*   Updated: 2025/11/16 11:35:05 by mohassaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// strlcat safely appends src to dest without overflowing,
// and returns the total length it wanted to build
size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	dest_len;
	size_t	src_len;

	dest_len = 0;
	src_len = 0;
	while (dest[dest_len])
		dest_len++;
	while (src[src_len])
		src_len++;
	if (size <= dest_len)
		return (size + src_len);
	i = dest_len;
	j = 0;
	while (src[j] && i < size - 1)
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	dest[i] = '\0';
	return (dest_len + src_len);
}
/*
int	main(void)
{
	char	src[] = "World";
	char	dest[20] = "Hello";
	size_t	dest_len;
	size_t	src_len;
	size_t	supposed_len;

	dest_len = 0;
	supposed_len = ft_strlcat(dest,src,3);
	while (dest[dest_len])
		dest_len++;
	//printf("%ld/n", dest_len);
	// the size of the dest is the min(size-1 && src_len + dest_len)
	printf("The destination is: %s\nThe length of the destination is:
		%ld\nThe total length it wanted to create is: %ld",dest,
		dest_len,supposed_len);
}*/
