/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrasolom <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 14:53:21 by hrasolom          #+#    #+#             */
/*   Updated: 2024/04/22 11:56:03 by hrasolom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar_pf(int a)
{
	write(1, &a, 1);
	return (1);
}

int	ft_printp(void)
{
	write(1, "%", 1);
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
	else if (format == 'p')
		print += ft_printptr(va_arg(lists, unsigned long));
	else if (format == 'd' || format == 'i')
		print += ft_printnbr(va_arg(lists, int));
	else if (format == 'u')
		print += ft_printu(va_arg(lists, unsigned int));
	else if (format == 'x' || format == 'X')
		print += ft_printhex(va_arg(lists, unsigned int), format);
	else if (format == '%')
		print += ft_printp();
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
	while (str [a])
	{
		if (str [a] == '%')
		{
			print += ft_prints(list, str [a + 1]);
			a++;
		}
		else
			print += ft_putchar_pf(str [a]);
		a++;
	}
	va_end(list);
	return (print);
}
