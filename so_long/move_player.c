/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrasolom <hrasolom@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 15:15:24 by hrasolom          #+#    #+#             */
/*   Updated: 2024/07/30 13:41:10 by hrasolom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_right(t_data *mlx)
{
	if (mlx->map[mlx->player->pos_y][mlx->player->pos_x + 1] != '1')
	{
		mlx->map[mlx->player->pos_y][mlx->player->pos_x] = '0';
		if (mlx->map[mlx->player->pos_y][mlx->player->pos_x + 1] == 'C')
		{
			mlx->count_c -= 1;
		}
		mlx->count_move++;
		ft_printf("count_move = %d\n", mlx->count_move);
		mlx->map[mlx->player->pos_y][mlx->player->pos_x + 1] = 'P';
		mlx->player->pos_x += 1;
	}
}

void	move_left(t_data *mlx)
{
	if (mlx->map[mlx->player->pos_y][mlx->player->pos_x - 1] != '1')
	{
		mlx->map[mlx->player->pos_y][mlx->player->pos_x] = '0';
		if (mlx->map[mlx->player->pos_y][mlx->player->pos_x - 1] == 'C')
		{
			mlx->count_c -= 1;
		}
		mlx->count_move++;
		ft_printf("count_move = %d\n", mlx->count_move);
		mlx->map[mlx->player->pos_y][mlx->player->pos_x - 1] = 'P';
		mlx->player->pos_x -= 1;
	}
}

void	move_up(t_data *mlx)
{
	if (mlx->map[mlx->player->pos_y - 1][mlx->player->pos_x] != '1')
	{
		mlx->map[mlx->player->pos_y][mlx->player->pos_x] = '0';
		if (mlx->map[mlx->player->pos_y - 1][mlx->player->pos_x] == 'C')
		{
			mlx->count_c -= 1;
		}
		mlx->count_move++;
		ft_printf("count_move = %d\n", mlx->count_move);
		mlx->map[mlx->player->pos_y - 1][mlx->player->pos_x] = 'P';
		mlx->player->pos_y -= 1;
	}
}

void	move_down(t_data *mlx)
{
	if (mlx->map[mlx->player->pos_y + 1][mlx->player->pos_x] != '1')
	{
		mlx->map[mlx->player->pos_y][mlx->player->pos_x] = '0';
		if (mlx->map[mlx->player->pos_y + 1][mlx->player->pos_x] == 'C')
		{
			mlx->count_c -= 1;
		}
		mlx->count_move++;
		ft_printf("count_move = %d\n", mlx->count_move);
		mlx->map[mlx->player->pos_y + 1][mlx->player->pos_x] = 'P';
		mlx->player->pos_y += 1;
	}
}
