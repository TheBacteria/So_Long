/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mz_game_launch_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzouine <mzouine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 03:15:28 by mzouine           #+#    #+#             */
/*   Updated: 2024/03/08 17:50:37 by mzouine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static void	mz_map_initialize(t_map *map)
{
	int	x;
	int	y;

	map->mlx = mlx_init();
	map->count = 0;
	if (map->mlx == NULL)
	{
		mz_free_map(map->map);
		ft_putstr_fd("Error\nmlx error !", 2);
		exit(1);
	}
	map->win = mlx_new_window(map->mlx, 64 * map->map_w, 64 * map->map_h, "sl");
	map->p_img = mlx_xpm_file_to_image(map->mlx, "textures/st_ft.xpm", &x, &y);
	map->ex_img = mlx_xpm_file_to_image(map->mlx, "textures/ir_d.xpm", &x, &y);
	map->c_img = mlx_xpm_file_to_image(map->mlx, "textures/d1.xpm", &x, &y);
	map->b_img = mlx_xpm_file_to_image(map->mlx, "textures/cobble.xpm", &x, &y);
	map->wall_img = mlx_xpm_file_to_image(map->mlx, "textures/obs.xpm", &x, &y);
	map->x_img = mlx_xpm_file_to_image(map->mlx, "textures/zmb_ft.xpm", &x, &y);
	map->w_img = mlx_xpm_file_to_image(map->mlx, "textures/zmb_bk.xpm", &x, &y);
	map->y_img = mlx_xpm_file_to_image(map->mlx, "textures/zmb_lt.xpm", &x, &y);
	map->z_img = mlx_xpm_file_to_image(map->mlx, "textures/zmb_rt.xpm", &x, &y);
	if (map->win == NULL || map->p_img == NULL || map->ex_img == NULL
		|| map->c_img == NULL || map->b_img == NULL || map->wall_img == NULL
		|| map->x_img == NULL)
		mz_texture_fail(map);
}

static int	mz_move(int key, t_map *map)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	if (key == KEY_W && (map->map[map->p_y - 1][map->p_x] != '1'))
		mz_up(map, x, y);
	if (key == KEY_S && (map->map[map->p_y + 1][map->p_x] != '1'))
		mz_down(map, x, y);
	if (key == KEY_A && (map->map[map->p_y][map->p_x - 1] != '1'))
		mz_left(map, x, y);
	if (key == KEY_D && (map->map[map->p_y][map->p_x + 1] != '1'))
		mz_right(map, x, y);
	if (key == KEY_ESC)
		mz_esc(map);
	if (mz_check_col(map) == 0)
		map->ex_img = mlx_xpm_file_to_image(map->mlx, "textures/n.xpm", &x, &y);
	if (map->ex_img == NULL)
		mz_texture_fail(map);
	mz_map_print(map);
	return (0);
}

static void	mz_animation(t_map *map, int count)
{
	int	x;
	int	y;

	if (count == 5)
		map->c_img = mlx_xpm_file_to_image(map->mlx, "textures/d1.xpm", &x, &y);
	else if (count == 10)
		map->c_img = mlx_xpm_file_to_image(map->mlx, "textures/d2.xpm", &x, &y);
	else if (count == 15)
		map->c_img = mlx_xpm_file_to_image(map->mlx, "textures/d3.xpm", &x, &y);
	else if (count == 20)
		map->c_img = mlx_xpm_file_to_image(map->mlx, "textures/d4.xpm", &x, &y);
	else if (count == 25)
		map->c_img = mlx_xpm_file_to_image(map->mlx, "textures/d5.xpm", &x, &y);
	else if (count == 30)
		map->c_img = mlx_xpm_file_to_image(map->mlx, "textures/d6.xpm", &x, &y);
	else if (count == 35)
		map->c_img = mlx_xpm_file_to_image(map->mlx, "textures/d7.xpm", &x, &y);
	else if (count == 40)
		map->c_img = mlx_xpm_file_to_image(map->mlx, "textures/d8.xpm", &x, &y);
	else if (count == 45)
		map->c_img = mlx_xpm_file_to_image(map->mlx, "textures/d1.xpm", &x, &y);
	if (map->c_img == NULL)
		mz_texture_fail(map);
	mz_map_print(map);
}

static int	mz_loop(t_map *map)
{
	static int	count;

	mz_animation(map, count);
	if (count % 20 == 0)
		mz_zombie(map, count);
	count++;
	if (count == 50)
		count = 0;
	return (0);
}

void	mz_game_launch(t_map *map)
{
	mz_map_initialize(map);
	mz_map_print(map);
	mlx_hook(map->win, X_EVENT_KEY_PRESS, 0, mz_move, map);
	mlx_hook(map->win, 17, 0, mz_esc, map);
	mlx_loop_hook(map->mlx, mz_loop, map);
	mlx_loop(map->mlx);
}
