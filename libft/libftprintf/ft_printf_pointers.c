/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_pointers.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohassaf <mohassaf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 19:36:49 by mohassaf          #+#    #+#             */
/*   Updated: 2026/01/23 14:00:07 by mohassaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

static int	ft_count_hexa_v2(unsigned long n)
{
	int	count;

	if (!n)
		return (5);
	count = 0;
	while (n)
	{
		n = n / 16;
		count++;
	}
	return (count + 2);
}

static int	ft_hexa_lower_v2(unsigned long i)
{
	int	count;

	count = ft_count_hexa_v2(i);
	if (i <= 9)
		ft_putchar_fd(i + '0', 1);
	else if (i > 9 && i < 16)
		ft_putchar_fd(i + 87, 1);
	else
	{
		ft_hexa_lower_v2(i / 16);
		ft_hexa_lower_v2(i % 16);
	}
	return (count);
}

static int	ft_print_full_pointer(t_flags list, unsigned long l)
{
	ft_putstr_fd("0x", 1);
	precision_flag(list, ft_count_hexa_v2(l));
	ft_hexa_lower_v2(l);
	return (ft_count_hexa_v2(l));
}

static int	ft_pointer(t_flags list, unsigned long l)
{
	if (!l)
	{
		ft_putstr_fd("(nil)", 1);
		return (5);
	}
	return (ft_print_full_pointer(list, l));
}

int	ft_printf_pointers(t_flags list, va_list *args)
{
	void			*p;
	unsigned long	l;

	p = (void *)va_arg(*args, void *);
	l = (unsigned long)p;
	if (list.minus == 0)
		return (width_flag(list, max(list.precision, ft_count_hexa_v2(l)))
			+ ft_pointer(list, l));
	else
		return (ft_pointer(list, l) + width_flag(list, max(list.precision,
					ft_count_hexa_v2(l))));
	return (0);
}
