/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mz_map_print.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzouine <mzouine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 06:04:07 by mzouine           #+#    #+#             */
/*   Updated: 2024/03/03 10:03:53 by mzouine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	mz_print(t_map *map, char c, int x, int y)
{
	if (c == 'P')
	{
		mlx_put_image_to_window(map->mlx, map->win, map->b_img, x, y);
		mlx_put_image_to_window(map->mlx, map->win, map->p_img, x, y);
	}
	else if (c == 'C')
	{
		mlx_put_image_to_window(map->mlx, map->win, map->b_img, x, y);
		mlx_put_image_to_window(map->mlx, map->win, map->c_img, x, y);
	}
	else if (c == 'E')
	{
		mlx_put_image_to_window(map->mlx, map->win, map->b_img, x, y);
		mlx_put_image_to_window(map->mlx, map->win, map->ex_img, x, y);
	}
	else if (c == '0')
		mlx_put_image_to_window(map->mlx, map->win, map->b_img, x, y);
	else if (c == '1')
		mlx_put_image_to_window(map->mlx, map->win, map->wall_img, x, y);
}

void	mz_map_print(t_map *map)
{
	int	i;
	int	j;

	j = 0;
	while (map->map[j])
	{
		i = 0;
		while (map->map[j][i])
		{
			mz_print(map, map->map[j][i], i * 64, j * 64);
			i++;
		}
		j++;
	}
}
