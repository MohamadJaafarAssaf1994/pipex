/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_hexa.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohassaf <mohassaf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 16:46:57 by mohassaf          #+#    #+#             */
/*   Updated: 2026/01/23 13:59:30 by mohassaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

int	ft_count_hexa(unsigned int n, int precision)
{
	int	count;

	if (!n && !precision)
		return (0);
	if (!n)
		return (1);
	count = 0;
	while (n)
	{
		n = n / 16;
		count++;
	}
	return (count);
}
