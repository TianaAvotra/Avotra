/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrasolom <hrasolom@student.42antanana      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 17:06:06 by hrasolom          #+#    #+#             */
/*   Updated: 2024/03/02 17:17:34 by hrasolom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	rec(int nb, int fd)
{
	char	c;

	if (!nb)
		return ;
	rec(nb / 10, fd);
	c = nb % 10 + '0';
	write (fd, &c, 1);
}

void	ft_putnbr_fd(int n, int fd)
{
	char	c;

	if (n <= -2147483648)
		write (fd, "-2147483648", 11);
	else
	{
		if (n < 0)
		{
			write (fd, "-", 1);
			n *= -1;
		}
		rec(n / 10, fd);
		c = n % 10 + '0';
		write (fd, &c, 1);
	}
}
