/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrasolom <hrasolom@student.42antanana      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 14:59:16 by hrasolom          #+#    #+#             */
/*   Updated: 2024/03/02 16:58:39 by hrasolom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	a;

	i = ft_strlen((char *)s);
	a = (char)c;
	while (i >= 0)
	{
		if (s[i] == a)
			return ((char *)(s + i));
		i--;
	}
	return (NULL);
}
/*
#include <stdio.h>
int	main(void)
{
	char a[] = "Hello";
	int b = 'l';
	printf("%s", ft_strrchr(a, b));
}*/
