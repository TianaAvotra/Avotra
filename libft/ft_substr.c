/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrasolom <hrasolom@student.42antanana      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 12:06:38 by hrasolom          #+#    #+#             */
/*   Updated: 2024/02/28 12:16:30 by hrasolom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*s1;

	if (!s)
		len = 0;
	if (start >= ft_strlen(s))
		len = 0;
	else if (ft_strlen(s + start) < len)
		len = ft_strlen(s + start);
	s1 = malloc((len + 1) * sizeof(char));
	if (!s1)
		return (0);
	i = 0;
	while (i < len && start < ft_strlen(s) && s[start] != '\0')
	{
		s1[i] = s[start + i];
		i++;
	}
	s1[i] = '\0';
	return (s1);
}
/*
#include <stdio.h>
int	main(void)
{
	char a[] = "0123456789";
	printf("%s", ft_substr(a, 9, 10));
}*/
