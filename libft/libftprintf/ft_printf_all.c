/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_all.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohassaf <mohassaf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 20:34:48 by mohassaf          #+#    #+#             */
/*   Updated: 2026/01/23 13:59:44 by mohassaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

int	ft_printf_all(t_flags list, va_list *args)
{
	if (list.type == 'c')
		return (ft_printf_characters(list, args));
	else if (list.type == 's')
		return (ft_printf_strings(list, args));
	else if (list.type == 'p')
		return (ft_printf_pointers(list, args));
	else if (list.type == 'd')
		return (ft_printf_decimals(list, args));
	else if (list.type == 'i')
		return (ft_printf_decimals(list, args));
	else if (list.type == 'u')
		return (ft_printf_unsigned_decimals(list, args));
	else if (list.type == 'x')
		return (ft_printf_lowercase_hexadecimals(list, args));
	else if (list.type == 'X')
		return (ft_printf_uppercase_hexadecimals(list, args));
	else if (list.type == '%')
		return (ft_printf_percentage());
	return (1);
}
