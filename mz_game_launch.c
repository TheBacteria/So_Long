/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mz_game_launch.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzouine <mzouine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 03:15:28 by mzouine           #+#    #+#             */
/*   Updated: 2024/03/08 20:09:32 by mzouine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	mz_map_initialize(t_map *map)
{
	int	x;
	int	y;

	map->mlx = mlx_init();
	map->count = 0;
	if (map->mlx == NULL)
	{
		mz_free_map(map->map);
		ft_putstr_fd("Error\nmlx init error !", 2);
		exit(1);
	}
	map->win = mlx_new_window(map->mlx, 64 * map->map_w, 64 * map->map_h, "sl");
	map->p_img = mlx_xpm_file_to_image(map->mlx, "textures/s_f.xpm", &x, &y);
	map->ex_img = mlx_xpm_file_to_image(map->mlx, "textures/i_d.xpm", &x, &y);
	map->c_img = mlx_xpm_file_to_image(map->mlx, "textures/d.xpm", &x, &y);
	map->b_img = mlx_xpm_file_to_image(map->mlx, "textures/c.xpm", &x, &y);
	map->wall_img = mlx_xpm_file_to_image(map->mlx, "textures/o.xpm", &x, &y);
	if (map->win == NULL || map->p_img == NULL || map->ex_img == NULL
		|| map->c_img == NULL || map->b_img == NULL || map->wall_img == NULL)
	{
		mz_free_map(map->map);
		mlx_destroy_window(map->mlx, map->win);
		ft_putstr_fd("Error\nTexture loading error !", 2);
		exit(1);
	}
}

static int	mz_move(int key, t_map *map)
{
	if (key == KEY_W && (map->map[map->p_y - 1][map->p_x] != '1'))
		mz_up(map);
	if (key == KEY_S && (map->map[map->p_y + 1][map->p_x] != '1'))
		mz_down(map);
	if (key == KEY_A && (map->map[map->p_y][map->p_x - 1] != '1'))
		mz_left(map);
	if (key == KEY_D && (map->map[map->p_y][map->p_x + 1] != '1'))
		mz_right(map);
	if (key == KEY_ESC)
		mz_esc(map);
	return (0);
}

void	mz_game_launch(t_map *map)
{
	mz_map_initialize(map);
	mz_map_print(map);
	mlx_hook(map->win, X_EVENT_KEY_PRESS, 0, mz_move, map);
	mlx_hook(map->win, 17, 0, mz_esc, map);
	mlx_loop(map->mlx);
}
