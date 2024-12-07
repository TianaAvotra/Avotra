/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrasolom <hrasolom@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/27 13:39:00 by hrasolom          #+#    #+#             */
/*   Updated: 2024/07/30 13:40:47 by hrasolom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	count_player(char **map)
{
	int	i;
	int	j;
	int	count_p;

	count_p = 0;
	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'P')
				count_p++;
			j++;
		}
		i++;
	}
	if (count_p != 1)
		return (0);
	return (1);
}

int	count_collect(char **map, t_data *mlx)
{
	int	i;
	int	j;
	int	count_c;

	i = 0;
	count_c = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'C')
			{
				count_c++;
			}
			j++;
		}
		i++;
	}
	mlx->count_c = count_c;
	if (count_c < 1)
		return (0);
	return (1);
}

int	count_exit(char **map)
{
	int	i;
	int	j;
	int	count_e;

	i = 0;
	count_e = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'E')
				count_e++;
			j++;
		}
		i++;
	}
	if (count_e != 1)
		return (0);
	return (1);
}

void	name_ber(char *file_ber)
{
	int	len;

	len = ft_strlen(file_ber);
	if (len <= 4 || (file_ber[len - 1] != 'r' && file_ber[len - 2] != 'e'
			&& file_ber[len - 3] != 'b' && file_ber[len - 4] != '.'))
		exit(EXIT_FAILURE);
}
