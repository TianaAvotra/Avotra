/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrasolom <hrasolom@student.42antanana      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 09:32:18 by hrasolom          #+#    #+#             */
/*   Updated: 2024/03/06 10:32:35 by hrasolom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	count(char const *s, char c)
{
	size_t	count;
	size_t	a;

	count = 0;
	a = 0;
	while (s[a])
	{
		if (s[a] != c && (s[a + 1] == c || s[a + 1] == '\0'))
			count++;
		a++;
	}
	return (count);
}

static void	fill(char *new, char const *s, char c)
{
	size_t	a;

	a = 0;
	while (s[a] && s[a] != c)
	{
		new[a] = s[a];
		a++;
	}
	new[a] = '\0';
}

static void	split(char **tab, char const *s, char c)
{
	size_t	count;
	size_t	index;
	size_t	i;

	index = 0;
	i = 0;
	while (s[index])
	{
		count = 0;
		while (s[index + count] && s[index + count] != c)
			count++;
		if (count > 0)
		{
			tab[i] = malloc(sizeof(char) * (count + 1));
			if (!tab[i])
				return ;
			fill(tab[i], (s + index), c);
			i++;
			index = index + count;
		}
		else
			index++;
	}
	tab[i] = 0;
}

char	**ft_split(char const *s, char c)
{
	size_t	w;
	char	**tab;

	w = count(s, c);
	tab = malloc(sizeof(char *) * (w + 1));
	if (!tab)
		return (NULL);
	split(tab, s, c);
	return (tab);
}

/*
#include <stdio.h>
int main(void)
{
	char  const string[] = "split this for me !";
	printf("%s", (char *)ft_split(string, ' ')[0]);
}*/
