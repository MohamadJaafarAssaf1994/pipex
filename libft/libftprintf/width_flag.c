/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   width_flag.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohassaf <mohassaf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/13 12:45:15 by mohassaf          #+#    #+#             */
/*   Updated: 2026/01/23 14:01:17 by mohassaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

int	width_flag(t_flags list, int len)
{
	int	width;

	if (list.type == 'x' || list.type == 'X' || list.type == 'd'
		|| list.type == 'i' || list.type == 'u')
		if (list.zero == 1)
			return (0);
	if (list.width == 0)
		return (0);
	width = list.width;
	if (width < len)
		return (0);
	else
		while (width-- - len)
			ft_putchar_fd(' ', 1);
	return (list.width - len);
}
