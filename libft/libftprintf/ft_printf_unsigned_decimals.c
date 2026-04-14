/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_unsigned_decimals.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohassaf <mohassaf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 20:14:59 by mohassaf          #+#    #+#             */
/*   Updated: 2026/01/23 14:00:15 by mohassaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

static size_t	ft_countdigits_v2(unsigned int n)
{
	size_t	count;

	count = 0;
	while (n)
	{
		n /= 10;
		count++;
	}
	return (count);
}

static char	*ft_itoa_v2(unsigned int n)
{
	char	*result;
	size_t	len;

	if (n == 0)
		return (ft_strdup("0"));
	len = ft_countdigits_v2(n);
	result = malloc((len + 1) * sizeof(char));
	if (!result)
		return (NULL);
	result[len] = '\0';
	while (n)
	{
		result[len - 1] = (n % 10) + '0';
		len--;
		n /= 10;
	}
	return (result);
}

static int	ft_print_all_cases(t_flags list, char *str)
{
	int	len;

	len = 0;
	if (list.minus == 0)
		len = width_flag(list, max(list.precision, ft_strlen_v2(list, str)))
			+ zero_flag(list, max(list.precision, ft_strlen_v2(list, str)))
			+ precision_flag(list, ft_strlen_v2(list, str)) + string(list, str);
	else
		len = precision_flag(list, ft_strlen_v2(list, str)) + string(list, str)
			+ width_flag(list, max(list.precision, ft_strlen_v2(list, str)));
	return (len);
}

int	ft_printf_unsigned_decimals(t_flags list, va_list *args)
{
	int		i;
	char	*s;
	size_t	len;

	len = 0;
	i = (unsigned)va_arg(*args, unsigned int);
	s = ft_itoa_v2(i);
	len = ft_print_all_cases(list, s);
	free(s);
	return (len);
}
