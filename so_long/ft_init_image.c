q/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_image.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrasolom <hrasolom@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/27 14:03:16 by hrasolom          #+#    #+#             */
/*   Updated: 2024/08/02 14:56:17 by hrasolom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_image(t_data *mlx)
{
	if (mlx->img_background == NULL || mlx->img_c == NULL
		|| mlx->img_door == NULL || mlx->img_man2 == NULL
		|| mlx->img_wall == NULL)
	{
		ft_putendl_fd("Error", 2);
		ft_clean_image(mlx);
		if (mlx->map)
			map_free(mlx->map);
		if (mlx->mlx)
		{
			mlx_destroy_display(mlx->mlx);
			free(mlx->mlx);
		}
		exit(EXIT_FAILURE);
	}
}

void	init_image(t_data *mlx)
{
	int	img_height;
	int	img_width;

	mlx->img_wall = mlx_xpm_file_to_image(mlx->mlx, "xpm/wall.xpm", &img_width,
			&img_height);
	mlx->img_background = mlx_xpm_file_to_image(mlx->mlx, "xpm/background.xpm",
			&img_width, &img_height);
	mlx->img_man2 = mlx_xpm_file_to_image(mlx->mlx, "xpm/man2.xpm", &img_width,
			&img_height);
	mlx->img_c = mlx_xpm_file_to_image(mlx->mlx, "xpm/c.xpm", &img_width,
			&img_height);
	mlx->img_door = mlx_xpm_file_to_image(mlx->mlx, "xpm/door.xpm", &img_width,
			&img_height);
}

void	image(char **map, t_data *mlx, int i, int j)
{
	if (map[j][i] == '1')
		mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img_wall, i * 32, j
			* 32);
	else
		mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img_background, i * 32,
			j * 32);
	if (map[j][i] == 'P')
		mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img_man2, i * 32, j
			* 32);
	if (map[j][i] == 'C')
		mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img_c, i * 32, j * 32);
}

void	image_e(t_data *mlx)
{
	if (mlx->count_c == 0)
		mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img_door,
			mlx->player->exit_x * 32, mlx->player->exit_y * 32);
}

void	put_image(char **map, t_data *mlx)
{
	int	i;
	int	j;

	j = -1;
	init_image(mlx);
	check_image(mlx);
	if (mlx->win)
	{
		while (map[++j])
		{
			i = -1;
			while (map[j][++i])
			{
				image(map, mlx, i, j);
				image_e(mlx);
			}
		}
	}
	ft_clean_image(mlx);
	exit_final(mlx);
}
