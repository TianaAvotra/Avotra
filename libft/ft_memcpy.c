/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrasolom <hrasolom@student.42antanana      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 16:28:07 by hrasolom          #+#    #+#             */
/*   Updated: 2024/02/28 15:56:50 by hrasolom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*a;
	unsigned char	*b;

	i = 0;
	a = (unsigned char *)dest;
	b = (unsigned char *)src;
	if (!a && !b)
		return (NULL);
	while (i < n)
	{
		a[i] = b[i];
		i++;
	}
	return (a);
}
/*
#include <stdio.h>
int	main(void)
{
	char d[] = "";
	char c[] = "hello";
	printf("%s",(char *)ft_memcpy(c, d, 5));v
}*/
