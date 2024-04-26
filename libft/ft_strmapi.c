/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrasolom <hrasolom@student.42antanana      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 16:40:39 by hrasolom          #+#    #+#             */
/*   Updated: 2024/03/04 17:43:54 by hrasolom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	strlen(char const *s)
{
	size_t	i;

	i = 0;
	while (*(s + i))
		i++;
	return (i);
}

static char	*new_str(size_t n)
{
	char	*s;

	s = malloc(sizeof(char) * (n + 1));
	if (!s)
		return (NULL);
	return (s);
}

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	i;
	char	*s1;
	char	*res;

	if (!s)
		return (NULL);
	s1 = new_str(strlen(s));
	if (! s1)
		return (NULL);
	i = 0;
	res = s1;
	while (*s)
		*s1++ = f(i++,*s++);
	*s1 = '\0';
	return (res);
}
