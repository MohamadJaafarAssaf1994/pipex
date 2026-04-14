/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen_v2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohassaf <mohassaf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/13 14:06:39 by mohassaf          #+#    #+#             */
/*   Updated: 2026/01/23 14:00:33 by mohassaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

int	ft_strlen_v2(t_flags list, char *str)
{
	if (ft_strncmp(str, "0", 2) == 0 && list.precision == 0)
		return (0);
	return (ft_strlen(str));
}
