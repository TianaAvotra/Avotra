/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrasolom <hrasolom@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 16:55:39 by hrasolom          #+#    #+#             */
/*   Updated: 2024/06/29 10:41:02 by hrasolom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pb(t_list **a, t_list **b)
{
	t_list	*tmp;

	if ((*a) == NULL)
		return ;
	else
	{
		tmp = (*a);
		(*a) = (*a)->next;
		tmp->next = (*b);
		(*b) = tmp;
		write(1, "pb\n", 3);
	}
}

void	pa(t_list **a, t_list **b)
{
	t_list	*tmp;

	if ((*b) == NULL)
		return ;
	else
	{
		tmp = (*b);
		(*b) = (*b)->next;
		tmp->next = (*a);
		(*a) = tmp;
		write(1, "pa\n", 3);
	}
}
