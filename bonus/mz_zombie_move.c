/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mz_zombie_move.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzouine <mzouine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 20:54:53 by mzouine           #+#    #+#             */
/*   Updated: 2024/03/08 17:27:11 by mzouine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	mz_zombie_move_up(t_map *map, int y, int x)
{
	if (map->map[y - 1][x] == 'P')
		mz_lost(map);
	if (map->map[y - 1][1] == '0')
	{
		map->map[y - 1][x] = 'W';
		map->map[y][x] = '0';
		if (map->x_img == NULL)
			mz_texture_fail(map);
	}
	return (0);
}

int	mz_zombie_move_down(t_map *map, int y, int x)
{
	if (map->map[y + 1][x] == 'P')
		mz_lost(map);
	if (map->map[y + 1][x] == '0')
	{
		map->map[y + 1][x] = 'X';
		map->map[y][x] = '0';
		if (map->x_img == NULL)
			mz_texture_fail(map);
		return (2);
	}
	return (-1);
}

int	mz_zombie_move_right(t_map *map, int y, int x)
{
	if (map->map[y][x + 1] == 'P')
		mz_lost(map);
	if (map->map[y][x + 1] == '0')
	{
		map->map[y][x + 1] = 'Z';
		map->map[y][x] = '0';
		if (map->x_img == NULL)
			mz_texture_fail(map);
		return (1);
	}
	return (-1);
}

int	mz_zombie_move_left(t_map *map, int y, int x)
{
	if (map->map[y][x - 1] == 'P')
		mz_lost(map);
	if (map->map[y][x - 1] == '0')
	{
		map->map[y][x - 1] = 'Y';
		map->map[y][x] = '0';
		if (map->x_img == NULL)
			mz_texture_fail(map);
	}
	return (0);
}

int	mz_zombie_move(t_map *map, int y, int x)
{
	if ((map->map[y][x + 1] == 'P') || (map->map[y][x - 1] == 'P')
		|| (map->map[y - 1][x] == 'P') || (map->map[y + 1][x] == 'P'))
		mz_lost(map);
	if ((map->map[y][x + 1] <= map->map[y][x - 1]
		&& map->map[y][x + 1] <= map->map[y + 1][x]
		&& map->map[y][x + 1] <= map->map[y - 1][x]))
		return (mz_fix_map(map), mz_zombie_move_right(map, y, x));
	else if ((map->map[y][x - 1] <= map->map[y][x + 1]
		&& map->map[y][x - 1] <= map->map[y + 1][x]
		&& map->map[y][x - 1] <= map->map[y - 1][x]))
		return (mz_fix_map(map), mz_zombie_move_left(map, y, x));
	else if ((map->map[y - 1][x] <= map->map[y][x - 1]
		&& map->map[y - 1][x] <= map->map[y + 1][x]
		&& map->map[y - 1][x] <= map->map[y][x + 1]))
		return (mz_fix_map(map), mz_zombie_move_up(map, y, x));
	else if ((map->map[y + 1][x] <= map->map[y][x - 1]
		&& map->map[y + 1][x] <= map->map[y - 1][x]
		&& map->map[y + 1][x] <= map->map[y][x + 1]))
		return (mz_fix_map(map), mz_zombie_move_down(map, y, x));
	return (-1);
}
