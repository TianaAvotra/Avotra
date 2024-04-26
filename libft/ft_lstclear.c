/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrasolom <hrasolom@student.42antanana      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 16:17:01 by hrasolom          #+#    #+#             */
/*   Updated: 2024/03/09 16:23:06 by hrasolom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	if (! lst || ! del || !(*lst))
		return ;
	ft_lstclear(&(*lst)-> next, del);
	(del)((*lst)-> content);
	free (*lst);
	*lst = NULL;
}
