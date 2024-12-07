/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrasolom <hrasolom@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 13:01:02 by hrasolom          #+#    #+#             */
/*   Updated: 2024/06/29 16:50:43 by hrasolom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_double(t_list **stack)
{
	t_list	*nb1;
	t_list	*nb2;

	nb1 = *stack;
	while (nb1 != NULL)
	{
		nb2 = nb1->next;
		while (nb2 != NULL)
		{
			if (nb1->value == nb2->value)
			{
				ft_free(stack);
				write_error();
			}
			nb2 = nb2->next;
		}
		nb1 = nb1->next;
	}
}

static int	ft_in_order(t_list **a)
{
	t_list	*tmp;

	tmp = *a;
	while (tmp && tmp->next)
	{
		if (tmp->value > tmp->next->value)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

int	main(int argc, char **argv)
{
	t_list	*a;
	t_list	*b;

	(void)argc;
	init_stack(&a, &b, argv);
	check_double(&a);
	if (ft_in_order(&a))
		return (ft_free(&a), 0);
	init(a);
	push_a_to_b(&a, &b);
	init(b);
	while (stack_size(b) > 0)
	{
		target_search(&a, &b);
		pa(&a, &b);
		init(a);
		init(b);
	}
	move(&a);
	init(a);
	free_stack(a);
	return (0);
}
