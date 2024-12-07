/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrasolom <hrasolom@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 13:14:12 by hrasolom          #+#    #+#             */
/*   Updated: 2024/06/29 16:49:49 by hrasolom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_two(t_list **stack)
{
	if (stack_size(*stack) < 3)
	{
		if (stack_size(*stack) == 2)
		{
			if (((*stack)->value) > ((*stack)->next->value))
			{
				sa(stack);
			}
			return ;
		}
		return ;
	}
}

void	sort_three(t_list **stack)
{
	int	a;
	int	b;
	int	c;

	if (stack_size(*stack) < 3)
		sort_two(stack);
	else
	{
		a = (*stack)->value;
		b = (*stack)->next->value;
		c = (*stack)->next->next->value;
		if (a < b && b < c && a < c)
			return ;
		else if (a > b && b < c && c > a)
			sa(stack);
		else if (a < b && b > c && a > c)
			rra(stack);
		else if (a < b && b > c && a < c)
			return (rra(stack), sa(stack));
		else if (a > b && b > c && a > c)
			return (ra(stack), sa(stack));
		else if (a > b && b < c && a > c)
			ra(stack);
	}
}

void	init(t_list *list)
{
	int	indice;

	if (list == NULL)
		return ;
	indice = 0;
	while (list != NULL)
	{
		list->indice = indice;
		indice++;
		list = list->next;
	}
}

void	push_a_to_b(t_list **a, t_list **b)
{
	t_list	*i;
	int		size;

	i = (*a);
	size = stack_size(i);
	while (size > 3)
	{
		pb(a, b);
		size--;
	}
	sort_three(a);
}
