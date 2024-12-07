/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printhex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrasolom <hrasolom@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 13:43:10 by hrasolom          #+#    #+#             */
/*   Updated: 2024/07/30 13:43:10 by hrasolom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_len(unsigned int n)
{
	int	len;

	len = 0;
	while (n != 0)
	{
		len++;
		n = n / 16;
	}
	return (len);
}

static int	ft_putchar_fd(char a, int fd)
{
	write(fd, &a, 1);
	return (1);
}

void	ft_puthexan(unsigned int n, const char f)
{
	if (n >= 16)
	{
		ft_puthexan(n / 16, f);
		ft_puthexan(n % 16, f);
	}
	else
	{
		if (n <= 9)
			ft_putchar_fd((n + '0'), 1);
		else
		{
			if (f == 'x')
				ft_putchar_fd((n - 10 + 'a'), 1);
			if (f == 'X')
				ft_putchar_fd((n - 10 + 'A'), 1);
		}
	}
}

int	ft_printhex(unsigned int n, const char format)
{
	if (n == 0)
		return (write(1, "0", 1));
	else
		ft_puthexan(n, format);
	return (ft_len(n));
}
