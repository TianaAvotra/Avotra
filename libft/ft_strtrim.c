/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtirm.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrasolom <hrasolom@student.42antanana      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 10:52:18 by hrasolom          #+#    #+#             */
/*   Updated: 2024/03/04 11:50:01 by hrasolom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (!set)
		return ((char *)s1);
	while (s1[i] && ft_memchr(set, s1[i], ft_strlen(set)))
		i++;
	j = ft_strlen(s1);
	while (i < j && ft_memchr(set, s1[j - 1], ft_strlen(set)))
		j--;
	return (ft_substr(s1, i, j - i));
}
