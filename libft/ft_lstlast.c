/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohassaf <mohassaf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 17:20:25 by mohassaf          #+#    #+#             */
/*   Updated: 2025/12/01 13:44:57 by mohassaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

/*int main(void)
{
	t_list	*head;
	t_list	*a;
	t_list	*b;
	t_list	*c;

	head = NULL;
	a = ft_lstnew("first");
	b = ft_lstnew("second");
	c = ft_lstnew("zero");
	ft_lstadd_back(&head,a);
	ft_lstadd_back(&head,b);
	ft_lstadd_front(&head, c);
	printf("%s\n", (char *)ft_lstlast(head)->content);
}*/
