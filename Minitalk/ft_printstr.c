/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printstr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrasolom <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 12:10:20 by hrasolom          #+#    #+#             */
/*   Updated: 2024/04/22 12:11:33 by hrasolom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_putstr(char *str)
{
	int	a;

	a = 0;
	while (str[a])
	{
		write (1, &str[a], 1);
		a++;
	}
}

int	ft_printstr(char *str)
{
	int	a;
	int	i;

	a = 0;
	i = ft_strlen(str);
	if (str == NULL)
	{
		ft_putstr("(null)");
		return (6);
	}
	else
	{
		while (str[a])
		{
			write (1, &str[a], 1);
			a++;
		}
	}
	return (i);
}
