/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrasolom <hrasolom@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 17:34:12 by hrasolom          #+#    #+#             */
/*   Updated: 2024/08/02 15:23:31 by hrasolom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_data		mlx;
	int			fd;
	char		**map;
	char		**map_tmp;
	t_player	player;

	map = NULL;
	fd = 0;
	if (argc != 2)
		print_error();
	name_ber(argv[1]);
	map = scan_map(argv[1], fd);
	condition_map(argv[1], &mlx, map);
	position_player(map, &player);
	mlx.player = &player;
	map_tmp = tmp_map(map, &mlx);
	fill(map_tmp, player.pos_x, player.pos_y, mlx);
	if (check_map(map_tmp, mlx.y) == 0)
	{
		map_free(map);
		free_flood_file(map_tmp);
	}
	map_free(map_tmp);
	display(mlx.x, mlx.y, map, &mlx);
	return (0);
}
