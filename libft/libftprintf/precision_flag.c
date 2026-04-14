/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   precision_flag.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohassaf <mohassaf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/13 12:39:37 by mohassaf          #+#    #+#             */
/*   Updated: 2026/01/23 14:01:09 by mohassaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

int	precision_flag(t_flags list, int len)
{
	int	precision;

	precision = list.precision;
	if (precision < len)
		return (0);
	else
		while (precision-- - len)
			ft_putchar_fd('0', 1);
	return (list.precision - len);
}
