/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   position.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrasolom <hrasolom@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 15:19:21 by hrasolom          #+#    #+#             */
/*   Updated: 2024/07/30 13:40:15 by hrasolom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	position_player(char **map, t_player *player)
{
	int	j;
	int	i;

	j = 0;
	player->pos_x = 0;
	player->pos_y = 0;
	if (player == NULL)
		return ;
	while (map[j])
	{
		i = 0;
		while (map[j][i])
		{
			if (map[j][i] == 'P')
			{
				player->pos_x = i;
				player->pos_y = j;
				return ;
			}
			i++;
		}
		j++;
	}
}

void	position_exit(char **map, t_player *player)
{
	int	i;
	int	j;

	if (player == NULL)
		return ;
	j = 0;
	while (map[j])
	{
		i = 0;
		while (map[j][i])
		{
			if (map[j][i] == 'E')
			{
				player->exit_x = i;
				player->exit_y = j;
			}
			i++;
		}
		j++;
	}
}
