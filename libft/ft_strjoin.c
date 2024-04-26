/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrasolom <hrasolom@student.42antanana      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 12:16:42 by hrasolom          #+#    #+#             */
/*   Updated: 2024/02/28 12:49:29 by hrasolom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*p;
	size_t	t_len;
	int		i;

	i = 0;
	t_len = (ft_strlen(s1) + ft_strlen(s2));
	p = malloc(t_len + 1);
	if (!p)
		return (NULL);
	else
	{
		while (s1[i])
		{
			p[i] = s1[i];
			i++;
		}
		i = 0;
		while (s2[i])
		{
			p[ft_strlen(s1) + i] = s2[i];
			i++;
		}
	}
	p[ft_strlen(s1) + i] = '\0';
	return (p);
}
/*
#include <stdio.h>
int	main(void)
{
	char a[] = "he";
	char b[] = "llo";
	printf("%s", ft_strjoin(a, b));
}
*/
