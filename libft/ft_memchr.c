/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohassaf <mohassaf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/16 13:03:55 by mohassaf          #+#    #+#             */
/*   Updated: 2025/11/16 14:32:58 by mohassaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *memoryBlock, int searchedChar, size_t size)
{
	size_t			i;
	unsigned char	*p;

	i = 0;
	p = (unsigned char *)memoryBlock;
	while (size > 0)
	{
		if (p[i] == (unsigned char)searchedChar)
			return ((void *)(&p[i]));
		i++;
		size--;
	}
	return (NULL);
}
/*int	main(void)
{
	char	data[] = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100};
	int		size;
	void	*found;

	size = 10;
	found = ft_memchr(data, 57, size);
	printf("57 is %s\n", (found != NULL ? "found" : "not found"));
	found = ft_memchr(data, 50, size);
	printf("50 is %s\n", (found != NULL ? "found" : "not found"));
}*/
