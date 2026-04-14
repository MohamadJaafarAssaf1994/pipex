/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_uppercase_hexadecimals.c                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohassaf <mohassaf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 20:13:47 by mohassaf          #+#    #+#             */
/*   Updated: 2026/01/23 14:00:19 by mohassaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

static int	ft_hexa_upper(unsigned int i, int precision, int _switch)
{
	if (!i && !precision && !_switch)
		return (0);
	if (i <= 9)
		ft_putchar_fd(i + '0', 1);
	else if (i > 9 && i < 16)
		ft_putchar_fd(i + 55, 1);
	else
	{
		ft_hexa_upper(i / 16, precision, 1);
		ft_hexa_upper(i % 16, precision, 1);
	}
	return (ft_count_hexa(i, precision));
}

static int	sharp_flag(t_flags list, unsigned int i)
{
	if (!i || !list.sharp)
		return (0);
	else
		ft_putstr_fd("0X", 1);
	return (2);
}

static int	sharp_flag_count(t_flags list, unsigned int i)
{
	if (!i || !list.sharp)
		return (0);
	return (2);
}

static int	ft_print_all_cases(t_flags list, unsigned int i)
{
	int	len;

	len = 0;
	if (list.minus == 0)
		len = width_flag(list, sharp_flag_count(list, i) + max(list.precision,
					ft_count_hexa(i, list.precision))) + sharp_flag(list, i)
			+ zero_flag(list, sharp_flag_count(list, i) + max(list.precision,
					ft_count_hexa(i, list.precision))) + precision_flag(list,
				ft_count_hexa(i, list.precision)) + ft_hexa_upper(i,
				list.precision, 0);
	else
		len = sharp_flag(list, i) + precision_flag(list, ft_count_hexa(i,
					list.precision)) + ft_hexa_upper(i, list.precision, 0)
			+ width_flag(list, sharp_flag_count(list, i) + max(list.precision,
					ft_count_hexa(i, list.precision)));
	return (len);
}

int	ft_printf_uppercase_hexadecimals(t_flags list, va_list *args)
{
	unsigned int	i;
	int				len;

	i = (unsigned int)va_arg(*args, unsigned int);
	len = ft_print_all_cases(list, i);
	return (len);
}
