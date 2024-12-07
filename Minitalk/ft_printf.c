/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrasolom <hrasolom@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 14:53:21 by hrasolom          #+#    #+#             */
/*   Updated: 2024/07/15 08:39:51 by hrasolom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	ft_putchar_pf(int a)
{
	write(1, &a, 1);
	return (1);
}

int	ft_prints(va_list lists, const char format)
{
	int	print;

	print = 0;
	if (format == 'c')
		print += ft_putchar_pf(va_arg(lists, int));
	else if (format == 's')
		print += ft_printstr(va_arg(lists, char *));
	else if (format == 'd' || format == 'i')
		print += ft_printnbr(va_arg(lists, int));
	return (print);
}

int	ft_printf(const char *str, ...)
{
	int		a;
	va_list	list;
	int		print;

	a = 0;
	print = 0;
	va_start(list, str);
	while (str[a])
	{
		if (str[a] == '%')
		{
			print += ft_prints(list, str[a + 1]);
			a++;
		}
		else
			print += ft_putchar_pf(str[a]);
		a++;
	}
	va_end(list);
	return (print);
}
