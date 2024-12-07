/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printstr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrasolom <hrasolom@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 13:43:33 by hrasolom          #+#    #+#             */
/*   Updated: 2024/07/30 13:43:33 by hrasolom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	if (s == NULL)
		return (0);
	while (s[i] != '\0')
	{
		i++;
	}
	return (i);
}

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
