/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   target2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrasolom <hrasolom@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 10:55:41 by hrasolom          #+#    #+#             */
/*   Updated: 2024/06/29 12:24:04 by hrasolom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	search_instruction(t_list **a, t_list **b, int *instruction)
{
	t_list	*temp_a;
	t_list	*temp_b;
	int		min;
	int		i;

	min = 0;
	i = 0;
	while (++i < stack_size(*b))
		if (instruction[i] < instruction[min])
			min = i;
	temp_b = *b;
	i = -1;
	while (++i < min)
		temp_b = temp_b->next;
	move_element_to_top_b(b, temp_b);
	temp_a = (*a);
	while (temp_a->value != temp_b->target->value)
		temp_a = temp_a->next;
	move_element_to_top(a, temp_a);
	free(instruction);
}

void	target_search(t_list **a, t_list **b)
{
	t_list	*tmp_b;
	t_list	*max;
	int		*instruction;

	max = NULL;
	tmp_b = (*b);
	instruction = malloc(sizeof(int) * stack_size(tmp_b));
	while (tmp_b != NULL)
	{
		find_target(a, tmp_b, &max);
		instruction[tmp_b->indice] = count(max, stack_size(*a)) + count(tmp_b,
				stack_size(*b));
		tmp_b = tmp_b->next;
	}
	search_instruction(a, b, instruction);
}
