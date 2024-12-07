/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printptr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrasolom <hrasolom@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 13:43:24 by hrasolom          #+#    #+#             */
/*   Updated: 2024/07/30 13:43:24 by hrasolom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_len(unsigned long n)
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

static void	ft_putchar_fd(char a, int fd)
{
	write(fd, &a, 1);
}

void	ft_ptr(unsigned long n)
{
	if (n >= 16)
	{
		ft_ptr(n / 16);
		ft_ptr(n % 16);
	}
	else
	{
		if (n < 10)
			ft_putchar_fd((n + '0'), 1);
		else
			ft_putchar_fd((n - 10 + 'a'), 1);
	}
}

static void	ft_putstr(char *str)
{
	int	a;

	a = 0;
	while (str[a])
	{
		write (1, &str[a], 1);
		a++;
	}
}

int	ft_printptr(unsigned long p)
{
	int	print;

	print = 0;
	if ((char *)p == NULL)
	{
		ft_putstr("(nil)");
		return (5);
	}
	else
	{
		print += write (1, "0x", 2);
		ft_ptr(p);
		print += (ft_len(p));
	}
	return (print);
}
