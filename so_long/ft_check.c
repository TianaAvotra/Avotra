/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrasolom <hrasolom@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/27 13:43:17 by hrasolom          #+#    #+#             */
/*   Updated: 2024/08/02 15:24:58 by hrasolom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_rectangle_check(char **map)
{
	int	i;
	int	j;
	int	count;
	int	tmp;

	i = 0;
	tmp = 0;
	count = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j] != '\n' && map[i][j] != '\0')
		{
			count++;
			j++;
		}
		if (tmp == 0)
			tmp = count;
		else if (tmp != count)
			ft_free_map(map);
		count = 0;
		i++;
	}
	return (tmp);
}

int	check_map(char **map, int y)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (j < y)
		{
			if (map[i][j] != '1' && map[i][j] != 'F' && map[i][j] != '0')
			{
				return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}

void	display(int x, int y, char **map, t_data *mlx)
{
	mlx->mlx = mlx_init();
	mlx->win = NULL;
	mlx->count_move = 0;
	if (!mlx->mlx)
		exit(1);
	mlx->map = map;
	put_image(map, mlx);
	mlx->win = mlx_new_window(mlx->mlx, x * 32, y * 32, "So_long");
	if (!mlx->win)
	{
		free(mlx->mlx);
		exit(1);
	}
	put_image(map, mlx);
	mlx_hook(mlx->win, 2, 1L << 0, key_press, mlx);
	mlx_hook(mlx->win, 17, 1L << 17, close_window, mlx);
	mlx_loop(mlx->mlx);
}

void	condition_map(char *str, t_data *mlx, char **map)
{
	mlx->x = ft_rectangle_check(map);
	mlx->y = read_map_y(str);
	if (!ft_scan_wall(map, mlx->x, mlx->y, mlx))
		ft_free_map(map);
}

void	print_error(void)
{
	ft_putendl_fd("Error", 2);
	exit(EXIT_FAILURE);
}
