/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrasolom <hrasolom@student.42antanana      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 15:09:28 by hrasolom          #+#    #+#             */
/*   Updated: 2024/03/02 16:59:15 by hrasolom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	const char		*a;

	i = 0;
	a = (const char *)s;
	while (i < n)
	{
		if (a[i] == (char)c)
			return ((void *)&a[i]);
		i++;
	}
	return (NULL);
}
/*
#include <stdio.h>
int	main(void)
{
	char a[] = "Helllo";
	int	b = 'o';
	
	printf("%s",(char *)ft_memchr(a, b, 5));
}*/
