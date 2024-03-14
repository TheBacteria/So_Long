/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mz_flood_fill_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzouine <mzouine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 16:42:41 by mzouine           #+#    #+#             */
/*   Updated: 2024/03/08 16:53:05 by mzouine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static void	mz_flood_map(t_map *map, int x, int y)
{
	if (map->map[y][x] == '0' || map->map[y][x] == 'C')
	{
		if (map->map[y][x] == '0')
			map->map[y][x] = '.';
		else if (map->map[y][x] == 'C')
			map->map[y][x] = '9';
		mz_flood_map(map, x + 1, y);
		mz_flood_map(map, x - 1, y);
		mz_flood_map(map, x, y + 1);
		mz_flood_map(map, x, y - 1);
	}
}

static int	mz_exit_check(t_map *map)
{
	int	x;
	int	y;

	x = map->e_x;
	y = map->e_y;
	if (map->map[y + 1][x] == '.' || map->map[y + 1][x] == '9')
		return (0);
	if (map->map[y - 1][x] == '.' || map->map[y - 1][x] == '9')
		return (0);
	if (map->map[y][x + 1] == '.' || map->map[y][x + 1] == '9')
		return (0);
	if (map->map[y][x - 1] == '.' || map->map[y][x - 1] == '9')
		return (0);
	return (1);
}

static void	mz_fix_map2(t_map *map)
{
	int	i;
	int	j;

	j = 0;
	while (map->map[j])
	{
		i = 0;
		while (map->map[j][i])
		{
			if (map->map[j][i] == '.')
				map->map[j][i] = '0';
			else if (map->map[j][i] == '9')
				map->map[j][i] = 'C';
			i++;
		}
		j++;
	}
}

void	mz_flood_fill(t_map *map)
{
	mz_get_info(map);
	mz_flood_map(map, map->p_x + 1, map->p_y);
	mz_flood_map(map, map->p_x - 1, map->p_y);
	mz_flood_map(map, map->p_x, map->p_y + 1);
	mz_flood_map(map, map->p_x, map->p_y - 1);
	if (mz_exit_check(map) == 1)
	{
		mz_free_map(map->map);
		ft_putstr_fd("Error\nMap is Impossible !!\n", 2);
		exit(1);
	}
	if (mz_check_col(map) == 1)
	{
		mz_free_map(map->map);
		ft_putstr_fd("Error\nMap is Impossible !!\n", 2);
		exit(1);
	}
	mz_fix_map2(map);
}
