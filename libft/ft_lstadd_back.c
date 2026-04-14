/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohassaf <mohassaf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 16:31:36 by mohassaf          #+#    #+#             */
/*   Updated: 2025/11/28 14:00:16 by mohassaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*node;

	if (!lst || !new)
		return ;
	if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	node = *lst;
	while (node->next)
		node = node->next;
	node->next = new;
}
/*int main(void)
{
	t_list	*head;
	t_list	*a;
	t_list	*b;

	head = NULL;
	a = ft_lstnew("first");
	b = ft_lstnew("second");
	ft_lstadd_back(&head,a);
	ft_lstadd_back(&head,b);
	while (head)
	{
		printf("%s\n",(char *)head->content);
		head = head->next;
	}
}*/
