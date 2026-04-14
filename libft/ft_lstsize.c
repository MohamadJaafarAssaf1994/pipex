/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohassaf <mohassaf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 16:23:34 by mohassaf          #+#    #+#             */
/*   Updated: 2025/11/27 16:31:00 by mohassaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int	i;

	i = 0;
	while (lst)
	{
		i++;
		lst = lst->next;
	}
	return (i);
}
/*int	main(void)
{
	t_list	*head;
	t_list	*a;
	t_list	*b;
	t_list	*c;

	head = NULL;
	a = ft_lstnew("node1");
	b = ft_lstnew("node2");
	c = ft_lstnew("node3");
	ft_lstadd_front(&head, c);
	ft_lstadd_front(&head, b);
	ft_lstadd_front(&head, a);
	printf("List size = %d\n", ft_lstsize(head));
}*/
