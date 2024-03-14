/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mz_map_print_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzouine <mzouine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 06:04:07 by mzouine           #+#    #+#             */
/*   Updated: 2024/03/10 17:46:38 by mzouine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static void	mz_print_enemy(t_map *map, char c, int x, int y)
{
	if (c == 'X')
	{
		mlx_put_image_to_window(map->mlx, map->win, map->b_img, x, y);
		mlx_put_image_to_window(map->mlx, map->win, map->x_img, x, y);
	}
	else if (c == 'W')
	{
		mlx_put_image_to_window(map->mlx, map->win, map->b_img, x, y);
		mlx_put_image_to_window(map->mlx, map->win, map->w_img, x, y);
	}
	else if (c == 'Y')
	{
		mlx_put_image_to_window(map->mlx, map->win, map->b_img, x, y);
		mlx_put_image_to_window(map->mlx, map->win, map->y_img, x, y);
	}
	else if (c == 'Z')
	{
		mlx_put_image_to_window(map->mlx, map->win, map->b_img, x, y);
		mlx_put_image_to_window(map->mlx, map->win, map->z_img, x, y);
	}
}

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
	else if (c == 'X' || c == 'W' || c == 'Y' || c == 'Z')
		mz_print_enemy(map, c, x, y);
}

void	mz_map_print(t_map *map)
{
	int		i;
	int		j;
	char	*s;
	char	*tmp;
	char	*n;

	j = 0;
	s = ft_strdup("Moves: ");
	n = ft_itoa(map->count);
	tmp = s;
	s = ft_strjoin(s, n);
	free(tmp);
	free(n);
	while (map->map[j])
	{
		i = 0;
		while (map->map[j][i])
		{
			mz_print(map, map->map[j][i], i * 64, j * 64);
			mlx_string_put(map->mlx, map->win, 10, 20, 0x58e5ff, s);
			i++;
		}
		j++;
	}
	free(s);
}
