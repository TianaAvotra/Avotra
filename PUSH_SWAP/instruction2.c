/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruction2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrasolom <hrasolom@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 10:51:39 by hrasolom          #+#    #+#             */
/*   Updated: 2024/06/29 10:52:26 by hrasolom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_min_position(t_list **a)
{
	t_list	*min;
	t_list	*tmp;
	int		i;

	tmp = *a;
	min = find_min(a);
	i = 1;
	while (tmp != NULL)
	{
		if (min->value == tmp->value)
			break ;
		i++;
		tmp = tmp->next;
	}
	return (i);
}

int	get_max_position(t_list **a)
{
	t_list	*max;
	t_list	*tmp;
	int		i;

	tmp = *a;
	max = find_max(a);
	i = 1;
	while (tmp != NULL)
	{
		if (max->value == tmp->value)
			break ;
		i++;
		tmp = tmp->next;
	}
	return (i);
}

void	move(t_list **a)
{
	t_list	*tmp;
	int		size;
	int		position;
	t_list	*min;

	tmp = *a;
	position = get_min_position(a);
	size = stack_size(tmp);
	min = find_min(a);
	if (position <= size / 2)
	{
		while ((*a) != min)
			ra(a);
	}
	else if (position > size / 2)
	{
		while ((*a) != min)
			rra(a);
	}
}
