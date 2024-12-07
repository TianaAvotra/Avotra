/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrasolom <hrasolom@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 17:58:46 by hrasolom          #+#    #+#             */
/*   Updated: 2024/06/29 10:47:34 by hrasolom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_list	*ft_lstlast(t_list *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

static void	rotate(t_list **stack)
{
	t_list	*head;
	t_list	*last;

	head = (*stack);
	last = ft_lstlast(head);
	*stack = head->next;
	head->next = NULL;
	last->next = head;
}

void	ra(t_list **a)
{
	rotate(a);
	write(1, "ra\n", 3);
}

void	rb(t_list **b)
{
	rotate(b);
	write(1, "rb\n", 3);
}

void	rr(t_list **a, t_list **b)
{
	rotate(a);
	rotate(b);
	write(1, "rr\n", 3);
}
