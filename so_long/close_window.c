/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_window.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrasolom <hrasolom@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 12:31:13 by hrasolom          #+#    #+#             */
/*   Updated: 2024/08/02 15:39:30 by hrasolom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_mlx(t_data *data)
{
	if (data->map)
		map_free(data->map);
	if (data->win)
		mlx_destroy_window(data->mlx, data->win);
	if (data->mlx)
	{
		mlx_destroy_display(data->mlx);
		free(data->mlx);
	}
}

void	exit_final(t_data *mlx)
{
	position_exit(mlx->map, mlx->player);
	if (mlx->player == NULL)
		return ;
	if (mlx->player->exit_x == mlx->player->pos_x
		&& mlx->player->exit_y == mlx->player->pos_y && mlx->count_c == 0)
	{
		ft_printf("Congratulation you win \n");
		free_mlx(mlx);
		exit(EXIT_SUCCESS);
	}
}

int	key_press(int key_code, t_data *mlx)
{
	(void)mlx;
	if (key_code == 65307)
	{
		ft_printf("You left the game\n");
		free_mlx(mlx);
		exit(EXIT_SUCCESS);
	}
	else if (key_code == 119 || key_code == 115 || key_code == 97
		|| key_code == 100)
	{
		if (key_code == 100)
			move_right(mlx);
		else if (key_code == 97)
			move_left(mlx);
		else if (key_code == 119)
			move_up(mlx);
		else if (key_code == 115)
			move_down(mlx);
		put_image(mlx->map, mlx);
	}
	return (0);
}

int	close_window(t_data *mlx)
{
	free_mlx(mlx);
	ft_printf("You left the game\n");
	exit(EXIT_SUCCESS);
	return (0);
}
