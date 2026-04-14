/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_decimals.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohassaf <mohassaf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 20:02:28 by mohassaf          #+#    #+#             */
/*   Updated: 2026/01/23 13:59:54 by mohassaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

static int	ft_sign(int sign)
{
	if (sign == 0)
		return (0);
	ft_putchar_fd('-', 1);
	return (1);
}

static void	change(char **new_s, char *s, int *sign)
{
	if (!s || s[0] != '-')
		*new_s = ft_strdup(s);
	else
	{
		*new_s = malloc(ft_strlen(s));
		if (!(*new_s))
			return ;
		ft_strlcpy(*new_s, s + 1, 100);
		*sign = 1;
	}
	free(s);
}

static int	ft_print_all_cases(t_flags list, char *str, int sign)
{
	int	len;

	len = 0;
	if (list.minus == 0)
		len = plus_or_space_flag(list, sign, ' ') + width_flag(list,
				plus_or_space_flag_count(list, sign, '+')
				+ plus_or_space_flag_count(list, sign, ' ') + sign
				+ max(list.precision, ft_strlen_v2(list, str)))
			+ plus_or_space_flag(list, sign, '+') + ft_sign(sign)
			+ zero_flag(list, plus_or_space_flag_count(list, sign, '+')
				+ plus_or_space_flag_count(list, sign, ' ') + sign
				+ max(list.precision, ft_strlen_v2(list, str)))
			+ precision_flag(list, ft_strlen_v2(list, str)) + string(list, str);
	else
		len = plus_or_space_flag(list, sign, ' ') + plus_or_space_flag(list,
				sign, '+') + ft_sign(sign) + precision_flag(list,
				ft_strlen_v2(list, str)) + string(list, str) + width_flag(list,
				plus_or_space_flag_count(list, sign, '+')
				+ plus_or_space_flag_count(list, sign, ' ') + sign
				+ max(list.precision, ft_strlen_v2(list, str)));
	return (len);
}

int	ft_printf_decimals(t_flags list, va_list *args)
{
	int		i;
	char	*s;
	int		sign;
	int		len;
	char	*new_s;

	sign = 0;
	len = 0;
	i = (int)va_arg(*args, int);
	s = ft_itoa(i);
	change(&new_s, s, &sign);
	len = ft_print_all_cases(list, new_s, sign);
	free(new_s);
	return (len);
}
