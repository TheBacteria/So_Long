/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mz_mouvement_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzouine <mzouine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 07:04:29 by mzouine           #+#    #+#             */
/*   Updated: 2024/03/10 17:52:26 by mzouine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	mz_esc(t_map *map)
{
	mlx_destroy_image(map->mlx, map->p_img);
	mlx_destroy_image(map->mlx, map->x_img);
	mlx_destroy_image(map->mlx, map->w_img);
	mlx_destroy_image(map->mlx, map->y_img);
	mlx_destroy_image(map->mlx, map->z_img);
	mlx_destroy_image(map->mlx, map->b_img);
	mlx_destroy_image(map->mlx, map->ex_img);
	mlx_destroy_image(map->mlx, map->c_img);
	mlx_destroy_image(map->mlx, map->wall_img);
	mlx_destroy_window(map->mlx, map->win);
	mz_free_map(map->map);
	exit(0);
}

void	mz_right(t_map *map, int x, int y)
{
	char	c;

	c = map->map[map->p_y][map->p_x + 1];
	if (c == 'Y' || c == 'W' || c == 'X' || c == 'Z')
		mz_lost(map);
	if (map->map[map->p_y][map->p_x + 1] == 'E')
	{
		if (mz_check_col(map) == 1)
			return ;
		else
		{
			ft_putstr_fd("Congrats !!", 1);
			mz_esc(map);
		}
	}
	map->map[map->p_y][map->p_x + 1] = 'P';
	map->map[map->p_y][map->p_x] = '0';
	map->p_x = map->p_x + 1;
	map->count = map->count + 1;
	map->p_img = mlx_xpm_file_to_image(map->mlx, "textures/st_rt.xpm", &x, &y);
	if (map->p_img == NULL)
		mz_texture_fail(map);
}

void	mz_left(t_map *map, int x, int y)
{
	char	c;

	c = map->map[map->p_y][map->p_x - 1];
	if (c == 'Y' || c == 'W' || c == 'X' || c == 'Z')
		mz_lost(map);
	if (map->map[map->p_y][map->p_x - 1] == 'E')
	{
		if (mz_check_col(map) == 1)
			return ;
		else
		{
			ft_putstr_fd("Congrats !!", 1);
			mz_esc(map);
		}
	}
	map->map[map->p_y][map->p_x - 1] = 'P';
	map->map[map->p_y][map->p_x] = '0';
	map->p_x = map->p_x - 1;
	map->count = map->count + 1;
	map->p_img = mlx_xpm_file_to_image(map->mlx, "textures/st_lt.xpm", &x, &y);
	if (map->p_img == NULL)
		mz_texture_fail(map);
}

void	mz_down(t_map *map, int x, int y)
{
	char	c;

	c = map->map[map->p_y + 1][map->p_x];
	if (c == 'Y' || c == 'W' || c == 'X' || c == 'Z')
		mz_lost(map);
	if (map->map[map->p_y + 1][map->p_x] == 'E')
	{
		if (mz_check_col(map) == 1)
			return ;
		else
		{
			ft_putstr_fd("Congrats !!", 1);
			mz_esc(map);
		}
	}
	map->map[map->p_y + 1][map->p_x] = 'P';
	map->map[map->p_y][map->p_x] = '0';
	map->p_y = map->p_y + 1;
	map->count = map->count + 1;
	map->p_img = mlx_xpm_file_to_image(map->mlx, "textures/st_ft.xpm", &x, &y);
	if (map->p_img == NULL)
		mz_texture_fail(map);
}

void	mz_up(t_map *map, int x, int y)
{
	char	c;

	c = map->map[map->p_y - 1][map->p_x];
	if (c == 'Y' || c == 'W' || c == 'X' || c == 'Z')
		mz_lost(map);
	if (map->map[map->p_y - 1][map->p_x] == 'E')
	{
		if (mz_check_col(map) == 1)
			return ;
		else
		{
			ft_putstr_fd("Congrats !!\n", 1);
			mz_esc(map);
		}
	}
	map->map[map->p_y - 1][map->p_x] = 'P';
	map->map[map->p_y][map->p_x] = '0';
	map->p_y = map->p_y - 1;
	map->count = map->count + 1;
	map->p_img = mlx_xpm_file_to_image(map->mlx, "textures/st_bk.xpm", &x, &y);
	if (map->p_img == NULL)
		mz_texture_fail(map);
}
