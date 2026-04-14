/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_characters.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohassaf <mohassaf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 13:47:28 by mohassaf          #+#    #+#             */
/*   Updated: 2026/01/23 13:59:48 by mohassaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

static int	ft_putchar_v2(char c)
{
	ft_putchar_fd(c, 1);
	return (1);
}

int	ft_printf_characters(t_flags list, va_list *args)
{
	char	c;

	c = (char)va_arg(*args, int);
	if (list.minus == 0)
		return (width_flag(list, 1) + ft_putchar_v2(c));
	else
		return (ft_putchar_v2(c) + width_flag(list, 1));
	return (0);
}
