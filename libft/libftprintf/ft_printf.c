/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohassaf <mohassaf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 12:46:45 by mohassaf          #+#    #+#             */
/*   Updated: 2026/01/23 14:00:23 by mohassaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

static void	init_flags(t_flags *f)
{
	f->minus = 0;
	f->zero = 0;
	f->plus = 0;
	f->space = 0;
	f->sharp = 0;
	f->width = 0;
	f->precision = -1;
	f->type = '\0';
}

int	ft_printf(const char *str, ...)
{
	int		count;
	int		index;
	va_list	args;
	t_flags	list;

	count = ((index = 0));
	if (!str || *str == '\0')
		return (-1);
	va_start(args, str);
	while (str[index])
	{
		if (str[index] != '%')
		{
			ft_putchar_fd(str[index++], 1);
			count++;
		}
		else
		{
			init_flags(&list);
			set_flags(&list, str, &index);
			count += ft_printf_all(list, &args);
		}
	}
	va_end(args);
	return (count);
}
/*int main(void)
{
	ft_printf("%.2d", 2);
}*/
