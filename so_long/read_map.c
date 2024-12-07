/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrasolom <hrasolom@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 18:07:33 by hrasolom          #+#    #+#             */
/*   Updated: 2024/08/02 10:43:13 by hrasolom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdlib.h>

int	read_map_y(char *file)
{
	char	*s;
	int		fd;
	int		height;

	height = 0;
	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (-1);
	s = get_next_line(fd);
	if (!s)
	{
		close(fd);
		return (-1);
	}
	while (s)
	{
		height++;
		free(s);
		s = get_next_line(fd);
	}
	close(fd);
	return (height);
}

char	**scan_map(char *str, int fd)
{
	char	**map;
	char	*s;
	int		i;
	int		y;

	i = 0;
	y = read_map_y(str);
	map = malloc(sizeof(char *) * (y + 1));
	if (!map)
		return (NULL);
	fd = open(str, O_RDONLY);
	s = get_next_line(fd);
	while (s)
	{
		map[i] = ft_strdup(s);
		free(s);
		s = get_next_line(fd);
		i++;
	}
	map[i] = NULL;
	close(fd);
	return (map);
}

int	ft_scan_wall(char **map, int x, int y, t_data *mlx)
{
	int	i;

	if (count_collect(map, mlx) == 0 || count_exit(map) == 0
		|| count_player(map) == 0)
	{
		ft_free_map(map);
	}
	if (x <= 0 || y <= 0)
		return (0);
	i = 0;
	while (i < x)
	{
		if (map[0][i] != '1' || map[y - 1][i] != '1')
			return (0);
		i++;
	}
	i = 0;
	while (i < y)
	{
		if (map[i][0] != '1' || map[i][x - 1] != '1')
			return (0);
		i++;
	}
	return (1);
}

void	fill(char **map, int pos_x, int pos_y, t_data to_fill)
{
	if (pos_y < 0 || pos_y >= to_fill.y || pos_x < 0 || pos_x >= to_fill.x)
		return ;
	if (map[pos_y][pos_x] == '1' || map[pos_y][pos_x] == 'F')
		return ;
	map[pos_y][pos_x] = 'F';
	fill(map, pos_x - 1, pos_y, to_fill);
	fill(map, pos_x + 1, pos_y, to_fill);
	fill(map, pos_x, pos_y - 1, to_fill);
	fill(map, pos_x, pos_y + 1, to_fill);
}

char	**tmp_map(char **map, t_data *mlx)
{
	int		i;
	int		j;
	char	**map_tmp;

	i = 0;
	map_tmp = (char **)malloc(sizeof(char *) * (mlx->y + 1));
	if (!map_tmp)
		return (NULL);
	while (i < mlx->y)
	{
		map_tmp[i] = (char *)malloc(sizeof(char) * (mlx->x + 2));
		if (!map_tmp[i])
			return (NULL);
		j = 0;
		while (j <= mlx->x)
		{
			map_tmp[i][j] = map[i][j];
			j++;
		}
		map_tmp[i][j] = '\0';
		i++;
	}
	map_tmp[i] = NULL;
	return (map_tmp);
}
