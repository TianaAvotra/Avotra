/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrasolom <hrasolom@student.42antanana      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 14:33:26 by hrasolom          #+#    #+#             */
/*   Updated: 2024/03/04 16:21:40 by hrasolom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	nbr_len(long nbr)
{
	int	count;

	count = 0;
	if (nbr < 1)
		count++;
	while (nbr)
	{
		nbr /= 10;
		count++;
	}
	return (count);
}

static long long	val_abs(long long n)
{
	long long	nb;

	nb = 1;
	if (n < 0)
		nb *= -n ;
	else
		nb *= n;
	return (nb);
}

static char	*new(size_t n)
{
	char	*s;

	s = malloc(sizeof(char) * (n + 1));
	if (!s)
		return (NULL);
	return (s);
}

char	*ft_itoa(int n)
{
	int				len;
	int				sign;
	unsigned int	nb;
	char			*s;

	sign = 0;
	if (n < 0)
		sign = 1;
	len = nbr_len(n);
	s = new(len);
	if (!s)
		return (NULL);
	*(s + len) = '\0';
	nb = val_abs(n);
	while (len--)
	{
		*(s + len) = 48 + nb % 10;
		nb /= 10;
	}
	if (sign)
		*(s) = 45;
	return (s);
}
