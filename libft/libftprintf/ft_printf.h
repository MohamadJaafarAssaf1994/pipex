/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohassaf <mohassaf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 12:42:45 by mohassaf          #+#    #+#             */
/*   Updated: 2026/01/23 14:16:42 by mohassaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <limits.h>
# include <stdarg.h>
# include <stddef.h>

typedef struct s_flags
{
	int		minus;
	int		zero;
	int		plus;
	int		space;
	int		sharp;
	int		width;
	int		precision;
	char	type;
}			t_flags;

int			ft_printf(const char *str, ...);
int			ft_printf_characters(t_flags list, va_list *args);
int			ft_printf_strings(t_flags list, va_list *args);
int			ft_printf_pointers(t_flags list, va_list *args);
int			ft_printf_decimals(t_flags list, va_list *args);
int			ft_printf_unsigned_decimals(t_flags list, va_list *args);
int			ft_printf_lowercase_hexadecimals(t_flags list, va_list *args);
int			ft_printf_uppercase_hexadecimals(t_flags list, va_list *args);
int			ft_printf_percentage(void);
int			ft_count_hexa(unsigned int n, int precision);
int			ft_hexa_lower(unsigned int i, int precision, int _switch);
void		set_flags(t_flags *list, const char *str, int *index);
int			ft_printf_all(t_flags list, va_list *args);
int			precision_flag(t_flags list, int len);
int			width_flag(t_flags list, int len);
int			max(int a, int b);
int			zero_flag(t_flags list, int len);
int			ft_strlen_v2(t_flags list, char *str);
int			string(t_flags list, char *str);
int			plus_or_space_flag(t_flags list, int sign, char flag);
int			plus_or_space_flag_count(t_flags list, int sign, char flag);

#endif
