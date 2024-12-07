/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_libft.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrasolom <hrasolom@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 12:07:10 by hrasolom          #+#    #+#             */
/*   Updated: 2024/06/29 13:50:28 by hrasolom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long long int	ft_atoi(char *nptr)
{
	long long int	i;
	long long int	sign;
	long long int	result;

	result = 0;
	sign = 1;
	i = 0;
	while (nptr[i] == 32 || (nptr[i] >= 9 && nptr[i] <= 13))
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			sign = -1 * sign;
		if (nptr[i + 1] == '-' || nptr[i + 1] == '+')
			write_error();
		i++;
	}
	while ((nptr[i] >= '0' && nptr[i] <= '9'))
	{
		result = result * 10 + nptr[i] - 48;
		i++;
	}
	return (result * sign);
}

static size_t	ft_count(char const *s, char c)
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

char	**ft_split(char *s, char c)
{
	size_t	w;
	char	**tab;

	w = ft_count(s, c);
	tab = malloc(sizeof(char *) * (w + 1));
	if (!tab)
		return (NULL);
	split(tab, s, c);
	return (tab);
}
