/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohassaf <mohassaf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 18:18:52 by mohassaf          #+#    #+#             */
/*   Updated: 2026/02/16 12:51:30 by mohassaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <limits.h>

static int	ft_countdigits(int n)
{
	int	count;
	int	number;

	number = n;
	count = 0;
	if (number < 0)
	{
		number *= -1;
		count++;
	}
	while (number)
	{
		number /= 10;
		count++;
	}
	return (count);
}

char	*ft_itoa(int n)
{
	char	*result;
	int		len;

	if (n == INT_MIN)
		return (ft_strdup("-2147483648"));
	if (n == 0)
		return (ft_strdup("0"));
	len = ft_countdigits(n);
	result = malloc((len + 1) * sizeof(char));
	if (!result)
		return (NULL);
	result[len] = '\0';
	if (n < 0)
	{
		n *= -1;
		result[0] = '-';
	}
	while (n)
	{
		result[len - 1] = (n % 10) + '0';
		len--;
		n /= 10;
	}
	return (result);
}

/*int	main(void)
{
	printf("%s", ft_itoa(-2147483648));
}*/
