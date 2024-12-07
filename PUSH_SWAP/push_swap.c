/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrasolom <hrasolom@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 13:45:14 by hrasolom          #+#    #+#             */
/*   Updated: 2024/07/13 13:19:29 by hrasolom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

int	is_sorted(t_list *stack)
{
	t_list	*nbr;

	nbr = stack;
	while (nbr && nbr->next)
	{
		if (nbr->value > nbr->next->value)
		{
			return (0);
		}
		nbr = nbr->next;
	}
	return (1);
}

void	check_error(char *argv)
{
	int	i;

	i = 0;
	while (argv[i])
	{
		if (!ft_isdigit(argv[i]))
		{
			write_error();
		}
		i++;
	}
}

static void	unique(t_list **a, char *n)
{
	if ((ft_atoi(n) == 0) && !ft_strnstr(n, "0", 1))
	{
		write(1, "Error\n", 6);
		ft_free(a);
		exit(1);
	}
	if (ft_atoi(n) > INT_MAX)
	{
		write(1, "Error\n", 6);
		ft_free(a);
		exit(1);
	}
	ft_lstadd_back((a), ft_lstnew(ft_atoi(n)));
}

static void	more_nb(t_list **a, char *n)
{
	int		i;
	char	**tab;

	tab = ft_split(n, ' ');
	i = 0;
	while (tab[i])
	{
		if (ft_atoi(tab[i]) > INT_MAX || ft_atoi(tab[i]) < INT_MIN)
		{
			free_split(tab);
			free_stack(*a);
			write_error();
		}
		else
		{
			ft_lstadd_back(a, ft_lstnew(ft_atoi(tab[i])));
		}
		i++;
	}
	free_split(tab);
}

void	init_stack(t_list **a, t_list **b, char **argv)
{
	int	i;
	int	j;

	i = 1;
	j = 1;
	*a = NULL;
	*b = NULL;
	while (argv[j])
	{
		check_error(argv[j]);
		j++;
	}
	while (argv[i])
	{
		if (ft_strchr(argv[i], ' ') != NULL)
			more_nb(a, argv[i]);
		else
			unique(a, argv[i]);
		i++;
	}
	if (is_sorted(*a))
		return ;
}
