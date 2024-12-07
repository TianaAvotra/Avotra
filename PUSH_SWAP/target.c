/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   target.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrasolom <hrasolom@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/22 15:50:16 by hrasolom          #+#    #+#             */
/*   Updated: 2024/06/29 12:18:40 by hrasolom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	find_target(t_list **a, t_list *b, t_list **max)
{
	int		target;
	t_list	*tmp_a;

	tmp_a = (*a);
	target = INT_MAX;
	*max = NULL;
	while ((tmp_a) != NULL)
	{
		if ((tmp_a->value) > b->value && tmp_a->value < target)
		{
			target = (tmp_a)->value;
			*max = tmp_a;
		}
		tmp_a = tmp_a->next;
	}
	if (target == INT_MAX)
		*max = find_min(a);
	b->target = *max;
	b = b->next;
}

int	count(t_list *stack, int size)
{
	int	instruction;

	instruction = 0;
	if (stack == NULL)
		return (instruction);
	if (stack->indice <= (size / 2))
		instruction = stack->indice;
	else
		instruction = size - stack->indice;
	return (instruction);
}

void	move_element_to_top(t_list **stack, t_list *instructions)
{
	t_list	*tmp;
	int		size;
	int		position;

	tmp = *stack;
	position = instructions->indice;
	size = stack_size(tmp);
	if (position <= (size / 2))
	{
		while ((*stack)->value != instructions->value)
		{
			ra(stack);
			init(*stack);
		}
	}
	else if (position > (size / 2))
	{
		while ((*stack)->value != instructions->value)
		{
			rra(stack);
			init(*stack);
		}
	}
}

void	move_element_to_top_b(t_list **stack, t_list *instructions)
{
	t_list	*tmp;
	int		size;
	int		position;

	tmp = *stack;
	position = instructions->indice;
	size = stack_size(tmp);
	if (position <= (size / 2))
	{
		while ((*stack)->value != instructions->value)
		{
			rb(stack);
			init(*stack);
		}
	}
	else if (position > (size / 2))
	{
		while ((*stack)->value != instructions->value)
		{
			rrb(stack);
			init(*stack);
		}
	}
}

// void	search_instruction(t_list **a, t_list **b, int *instruction)
// {
// 	t_list	*temp_a;
// 	t_list	*temp_b;
// 	int		min;
// 	int		i;

// 	min = 0;
// 	i = 0;
// 	while (++i < stack_size(*b))
// 		if (instruction[i] < instruction[min])
// 			min = i;
// 	temp_b = *b;
// 	i = -1;
// 	while (++i < min)
// 		temp_b = temp_b->next;
// 	move_element_to_top_b(b, temp_b);
// 	temp_a = (*a);
// 	while (temp_a->value != temp_b->target->value)
// 		temp_a = temp_a->next;
// 	move_element_to_top(a, temp_a);
// 	free(instruction);
// }

// void	target_search(t_list **a, t_list **b)
// {
// 	t_list	*tmp_b;
// 	t_list	*max;
// 	int		*instruction;

// 	max = NULL;
// 	tmp_b = (*b);
// 	instruction = malloc(sizeof(int) * stack_size(tmp_b));
// 	while (tmp_b != NULL)
// 	{
// 		find_target(a, tmp_b, &max);
// 		instruction[tmp_b->indice] = count(max, stack_size(*a)) + count(tmp_b,
// 				stack_size(*b));
// 		tmp_b = tmp_b->next;
// 	}
// 	search_instruction(a, b, instruction);
// }
