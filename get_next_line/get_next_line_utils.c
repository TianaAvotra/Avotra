/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrasolom <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 13:17:14 by hrasolom          #+#    #+#             */
/*   Updated: 2024/04/08 14:50:43 by hrasolom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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

int	ft_strlen(const char	*s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strchr(const char *s, int c)
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

void	ft_bzero(void *s, unsigned int n)
{
	unsigned char	*p;

	p = s;
	while (n--)
		*p++ = '\0';
}

void	*ft_calloc(unsigned int count, unsigned int size)
{
	void	*p;

	p = malloc(count * size);
	if (!p)
		return (NULL);
	ft_bzero(p, size * count);
	return (p);
}
