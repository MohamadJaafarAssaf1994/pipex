/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohassaf <mohassaf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/16 11:33:59 by mohassaf          #+#    #+#             */
/*   Updated: 2026/02/20 15:38:03 by mohassaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int searchedChar)
{
	if (!str)
		return (NULL);
	while (*str)
	{
		if (*str == (char)searchedChar)
			return ((char *)str);
		str++;
	}
	if ((char)searchedChar == '\0')
		return ((char *)str);
	return (NULL);
}

/*#include <string.h>

int	main(void)
{
	char	str[] = "Hello World!";
	char	c;

	c = 'o';
	printf("%s", ft_strchr(str, '\0'));
	printf("%s", strchr(str, '\0'));
}*/
