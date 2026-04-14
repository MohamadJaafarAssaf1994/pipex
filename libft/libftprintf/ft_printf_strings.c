/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_strings.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohassaf <mohassaf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 15:49:59 by mohassaf          #+#    #+#             */
/*   Updated: 2026/01/23 14:00:11 by mohassaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

static char	*ft_precision(int precision, char *str)
{
	if (!str && !precision)
		return (NULL);
	if (!str && precision >= 0 && precision <= 5)
		return (NULL);
	if (str == NULL)
		return (ft_strdup("(null)"));
	if (precision == -1)
		return (ft_strdup(str));
	else
		return (ft_substr(str, 0, precision));
}

static int	ft_string(char *str)
{
	if (!str)
		return (0);
	ft_putstr_fd(str, 1);
	return (ft_strlen(str));
}

int	ft_printf_strings(t_flags list, va_list *args)
{
	char	*s;
	int		count;
	char	*substr;

	count = 0;
	s = (char *)va_arg(*args, char *);
	substr = ft_precision(list.precision, s);
	if (list.minus == 0)
		count = width_flag(list, ft_strlen(substr)) + ft_string(substr);
	else
		count = ft_string(substr) + width_flag(list, ft_strlen(substr));
	free(substr);
	return (count);
}
