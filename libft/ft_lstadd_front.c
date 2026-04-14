/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohassaf <mohassaf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 15:53:40 by mohassaf          #+#    #+#             */
/*   Updated: 2025/11/27 16:23:03 by mohassaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (!lst || !new)
		return ;
	new->next = *lst;
	*lst = new;
}
/*int	main(void)
{
	t_list	*head;
	t_list	*a;
	t_list	*b;

	head = NULL;
	a = ft_lstnew("first");
	b = ft_lstnew("second");
	ft_lstadd_front(&head, a);
	ft_lstadd_front(&head, b);
	printf("%s\n", (char *)head->content);
	head = head->next;
	printf("%s\n", (char *)head->content);
}*/
