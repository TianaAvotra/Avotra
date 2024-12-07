/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrasolom <hrasolom@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 10:58:13 by hrasolom          #+#    #+#             */
/*   Updated: 2024/06/29 10:48:48 by hrasolom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (!lst || !new)
		return ;
	new->next = *lst;
	*lst = new;
}

static void	reverse_rotate(t_list **stack)
{
	t_list	*last;
	t_list	*tmp;

	last = *stack;
	tmp = *stack;
	while (last->next)
	{
		tmp = last;
		last = last->next;
	}
	ft_lstadd_front(stack, last);
	tmp->next = NULL;
}

void	rra(t_list **a)
{
	reverse_rotate(a);
	write(1, "rra\n", 4);
}

void	rrb(t_list **b)
{
	reverse_rotate(b);
	write(1, "rrb\n", 4);
}

void	rrr(t_list **a, t_list **b)
{
	reverse_rotate(a);
	reverse_rotate(b);
	write(1, "rra\n", 4);
}
