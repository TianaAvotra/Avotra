/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrasolom <hrasolom@student.42antanana      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 11:16:21 by hrasolom          #+#    #+#             */
/*   Updated: 2024/02/28 13:10:38 by hrasolom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	char	*p;

	p = (char *)malloc(nmemb * size);
	if (!p)
		return (NULL);
	else
		ft_memset(p, 0, nmemb * size);
	return ((void *)p);
}
