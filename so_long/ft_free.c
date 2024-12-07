/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrasolom <hrasolom@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/27 13:51:12 by hrasolom          #+#    #+#             */
/*   Updated: 2024/08/02 13:48:56 by hrasolom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	map_free(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
}

void	ft_free_map(char **map)
{
	map_free(map);
	ft_putendl_fd("Your map is invalid", 2);
	exit(1);
}

void	ft_clean_image(t_data *image)
{
	if (image->img_c)
		mlx_destroy_image(image->mlx, image->img_c);
	if (image->img_background)
		mlx_destroy_image(image->mlx, image->img_background);
	if (image->img_door)
		mlx_destroy_image(image->mlx, image->img_door);
	if (image->img_man2)
		mlx_destroy_image(image->mlx, image->img_man2);
	if (image->img_wall)
		mlx_destroy_image(image->mlx, image->img_wall);
}

void	free_flood_file(char **map)
{
	map_free(map);
	ft_putendl_fd("The way is invalid", 2);
	exit(1);
}
