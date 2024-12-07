/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruction.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrasolom <hrasolom@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 15:14:28 by hrasolom          #+#    #+#             */
/*   Updated: 2024/06/29 10:52:55 by hrasolom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

t_list	*find_max(t_list **stack)
{
	t_list	*max;
	t_list	*i;

	if (stack == NULL)
	{
		return (NULL);
	}
	max = (*stack);
	i = (*stack);
	while (i)
	{
		if (i->value > max->value)
			max = i;
		i = i->next;
	}
	return (max);
}

t_list	*find_min(t_list **stack)
{
	t_list	*min;
	t_list	*i;

	if ((*stack) == NULL)
		return (NULL);
	min = (*stack);
	i = (*stack);
	while (i != NULL)
	{
		if (i->value < min->value)
			min = i;
		i = i->next;
	}
	return (min);
}

int	stack_size(t_list *stack)
{
	int	count;

	count = 0;
	while (stack)
	{
		count++;
		stack = stack->next;
	}
	return (count);
}

int	get_position(t_list *stack, long long int value)
{
	int	position;

	position = 0;
	while (stack)
	{
		if (stack->value == value)
			return (position);
		position++;
		stack = stack->next;
	}
	return (-1);
}
