/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_flags.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohassaf <mohassaf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 18:47:53 by mohassaf          #+#    #+#             */
/*   Updated: 2026/01/23 14:01:12 by mohassaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

static int	is_type(char c)
{
	return (c == 'c' || c == 's' || c == 'p' || c == 'd' || c == 'i' || c == 'u'
		|| c == 'x' || c == 'X' || c == '%' || c == 'a');
}

static void	one(t_flags *list, const char *str, int *index)
{
	(*index)++;
	while (str[*index] == '-' || str[*index] == '0' || str[*index] == '+'
		|| str[*index] == ' ' || str[*index] == '#')
	{
		if (str[*index] == '0')
			list->zero = 1;
		else if (str[*index] == ' ')
			list->space = 1;
		else if (str[*index] == '-')
			list->minus = 1;
		else if (str[*index] == '+')
			list->plus = 1;
		else if (str[*index] == '#')
			list->sharp = 1;
		(*index)++;
	}
}

static void	two(t_flags *list, const char *str, int *index)
{
	while (ft_isdigit(str[*index]))
	{
		list->width = list->width * 10 + (str[*index] - '0');
		(*index)++;
	}
	if (str[*index] == '.')
	{
		(*index)++;
		list->precision = 0;
		while (ft_isdigit(str[*index]))
		{
			list->precision = list->precision * 10 + (str[*index] - '0');
			(*index)++;
		}
	}
	if (is_type(str[*index]))
	{
		list->type = str[*index];
		(*index)++;
	}
}

static void	three(t_flags *list)
{
	if (list->minus)
		list->zero = 0;
	if (list->plus)
		list->space = 0;
	if (list->precision != -1 && (list->type == 'd' || list->type == 'i'
			|| list->type == 'u' || list->type == 'x' || list->type == 'X'))
		list->zero = 0;
}

void	set_flags(t_flags *list, const char *str, int *index)
{
	one(list, str, index);
	two(list, str, index);
	three(list);
}
