/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printu.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrasolom <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 10:20:53 by hrasolom          #+#    #+#             */
/*   Updated: 2024/04/22 12:17:38 by hrasolom         ###   ########.fr       */
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
		n = n / 10;
	}
	return (len);
}

char	*ft_uitoa(unsigned int n)
{
	char	*nb;
	int		len;

	len = ft_len(n);
	nb = (char *)malloc(sizeof(char) * (len + 1));
	if (! nb)
		return (0);
	nb[len] = '\0';
	while (n != 0)
	{
		nb[len - 1] = n % 10 + 48;
		n /= 10;
		len--;
	}
	return (nb);
}

int	ft_printu(unsigned int n)
{
	int		print;
	char	*nb;

	print = 0;
	if (n == 0)
		print += write(1, "0", 1);
	else
	{
		nb = ft_uitoa(n);
		print += ft_printstr(nb);
		free(nb);
	}
	return (print);
}
