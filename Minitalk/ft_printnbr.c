/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printnbr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrasolom <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 10:19:51 by hrasolom          #+#    #+#             */
/*   Updated: 2024/04/22 12:05:26 by hrasolom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	ft_printnbr(int n)
{
	int		len;
	char	*nb;

	len = 0;
	nb = ft_itoa(n);
	len = ft_printstr(nb);
	free(nb);
	return (len);
}
