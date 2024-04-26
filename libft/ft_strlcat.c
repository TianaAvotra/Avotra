/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrasolom <hrasolom@student.42antanana      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 14:08:13 by hrasolom          #+#    #+#             */
/*   Updated: 2024/03/01 13:55:48 by hrasolom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	len_src;
	size_t	len_dst;
	size_t	j;

	len_src = ft_strlen(src);
	len_dst = ft_strlen(dst);
	if (size == 0)
		return (len_src);
	if (size <= len_dst)
		return (size + len_src);
	i = len_dst;
	j = 0;
	while (src[j] != '\0' && i < size - 1)
	{
		dst[i] = src[j];
		i++;
		j++;
	}
	dst[i] = '\0';
	return (len_dst + len_src);
}
/*
#include <stdio.h>
int	main(void)
{
	char i[] = "hello";
	char a[] = "bonjour";
	printf("%zu\n", ft_strlcat(i, a, 8));
	printf("%s", i);
}*/
