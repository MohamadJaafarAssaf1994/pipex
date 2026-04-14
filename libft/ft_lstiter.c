/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohassaf <mohassaf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 18:18:57 by mohassaf          #+#    #+#             */
/*   Updated: 2025/11/27 18:28:46 by mohassaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	if (!lst || !f)
		return ;
	while (lst)
	{
		f(lst->content);
		lst = lst->next;
	}
}
/*void	to_upper(void *content)
{
	char	*str;

	str = (char *)content;
	while (*str)
	{
		if (*str >= 'a' && *str <= 'z')
			*str = *str - 32;
		str++;
	}
}

int	main(void)
{
	t_list	*n1;

	char s[] = "hello";
	n1 = ft_lstnew(s);
	printf("%s\n", (char *)n1->content);
	ft_lstiter(n1, to_upper);
	printf("%s\n", (char *)n1->content);
	return (0);
}*/
