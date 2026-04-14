/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohassaf <mohassaf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 10:10:23 by mohassaf          #+#    #+#             */
/*   Updated: 2025/11/28 16:48:39 by mohassaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void			*ptr;
	size_t			total;
	size_t			i;
	unsigned char	*byte_ptr;

	if (count == 0 || size == 0)
		return (malloc(1));
	total = count * size;
	if (size != 0 && total / size != count)
		return (NULL);
	ptr = malloc(total);
	if (!ptr)
		return (NULL);
	byte_ptr = (unsigned char *)ptr;
	i = 0;
	while (i < total)
	{
		byte_ptr[i] = 0;
		i++;
	}
	return (ptr);
}

/*#include <stdint.h>

int	main(void)
{
	printf("%zu\n", SIZE_MAX + 1);
	return (0);
}*/
