/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohassaf <mohassaf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 14:52:37 by mohassaf          #+#    #+#             */
/*   Updated: 2025/11/28 13:41:48 by mohassaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	len1;
	size_t	len2;
	char	*total;

	if (!s1 || !s2)
		return (NULL);
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	total = malloc((len1 + len2 + 1) * (sizeof(char)));
	if (!total)
		return (NULL);
	ft_strlcpy(total, s1, len1 + len2 + 1);
	ft_strlcat(total, s2, len1 + len2 + 1);
	return (total);
}
/*int	main(void)
{
	char	s1[] = "Hello ";
	char	s2[] = "World";
	char	*s3;

	s3 = ft_strjoin(s1, s2);
	printf("%s", s3);
	free(s3);
}*/
