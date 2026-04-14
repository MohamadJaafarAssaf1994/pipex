/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohassaf <mohassaf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/13 14:10:48 by mohassaf          #+#    #+#             */
/*   Updated: 2026/01/23 14:00:28 by mohassaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

int	string(t_flags list, char *str)
{
	if (ft_strncmp(str, "0", 2) == 0 && list.precision == 0)
		return (0);
	ft_putstr_fd(str, 1);
	return (ft_strlen(str));
}
