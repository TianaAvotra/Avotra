/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrasolom <hrasolom@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 16:30:41 by hrasolom          #+#    #+#             */
/*   Updated: 2024/06/29 10:48:21 by hrasolom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	swap(t_list **stack)
{
	int	tmp;

	if (!(*stack) || (*stack)->next == NULL)
		return ;
	tmp = (*stack)->value;
	(*stack)->value = (*stack)->next->value;
	(*stack)->next->value = tmp;
}

void	sa(t_list **a)
{
	swap(a);
	write(1, "sa\n", 3);
}

void	sb(t_list **b)
{
	swap(b);
	write(1, "sb\n", 3);
}

void	ss(t_list **b, t_list **a)
{
	swap(a);
	swap(b);
	write(1, "ss\n", 3);
}
