/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrasolom <hrasolom@student.42antanana      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 13:07:11 by hrasolom          #+#    #+#             */
/*   Updated: 2024/02/29 16:23:00 by hrasolom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t				i;

	i = n - 1;
	if ((unsigned char *)dest == NULL && (const unsigned char *)src == NULL)
		return (NULL);
	if ((const unsigned char *)src < (unsigned char *)dest
		&& (const unsigned char *)src + n > (unsigned char *)dest)
	{
		while (i != (size_t) - 1)
		{
			((unsigned char *)dest)[i] = ((const unsigned char *)src)[i];
			i--;
		}
	}
	else
	{
		i = 0;
		while (i < n)
		{
			((unsigned char *)dest)[i] = ((const unsigned char *)src)[i];
			i++;
		}
	}
	return (dest);
}
/*
#include <stdio.h>
int	main(void)
{
	char i[] = "hello";
	char a[] = "bonjour";
	printf("%s\n", (char *)ft_memmove(i, a, 8));
	printf("%s", i);
}*/
/*n = 5

src = lu
dest = world

loworld
lu*/
