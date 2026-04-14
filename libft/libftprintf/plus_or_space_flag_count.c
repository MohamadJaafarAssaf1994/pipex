/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plus_or_space_flag_count.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohassaf <mohassaf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/14 11:07:40 by mohassaf          #+#    #+#             */
/*   Updated: 2025/12/14 11:09:54 by mohassaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	plus_or_space_flag_count(t_flags list, int sign, char flag)
{
	if (flag == '+')
	{
		if (!list.plus || sign == 1)
			return (0);
		return (1);
	}
	if (flag == ' ')
	{
		if (!list.space || list.plus == 1 || sign == 1)
			return (0);
		return (1);
	}
	return (0);
}
