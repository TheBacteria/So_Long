/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mz_zombie_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzouine <mzouine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 13:37:58 by mzouine           #+#    #+#             */
/*   Updated: 2024/03/08 18:00:48 by mzouine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static void	mz_flood_map2(t_map *map, int x, int y, int i)
{
	if (i >= 47 || map->map[y][x] == '1' ||
		map->map[y][x] == 'X' || map->map[y][x] == 'E' || map->map[y][x] == 'P'
		|| map->map[y][x] == 'C' || map->map[y][x] == 'W'
		|| map->map[y][x] == 'Y' || map->map[y][x] == 'Z')
		return ;
	else if (map->map[y][x] == '0')
	{
		map->map[y][x] = i;
		i = i + 1;
		mz_flood_map2(map, x - 1, y, i);
		mz_flood_map2(map, x, y + 1, i);
		mz_flood_map2(map, x, y - 1, i);
	}
}

static void	mz_flood_map(t_map *map, int x, int y, int i)
{
	if (i >= 47 || map->map[y][x] == '1' ||
		map->map[y][x] == 'X' || map->map[y][x] == 'E' || map->map[y][x] == 'P'
		|| map->map[y][x] == 'C' || map->map[y][x] == 'W'
		|| map->map[y][x] == 'Y' || map->map[y][x] == 'Z')
		return ;
	else if (map->map[y][x] == '0' && map->c == 'x')
	{
		map->map[y][x] = i;
		i = i + 1;
		map->c = 'x';
		mz_flood_map(map, x, y + 1, i);
	}
	else if (map->map[y][x] == '0')
	{
		map->map[y][x] = i;
		i = i + 1;
		map->c = 'r';
		mz_flood_map(map, x + 1, y, i);
		map->c = 'd';
		mz_flood_map(map, x, y + 1, i);
		map->c = 'u';
		mz_flood_map(map, x, y - 1, i);
	}
}

static int	mz_zombie_order(t_map *map, int y, int x)
{
	int	i;

	i = 1;
	map->c = 'r';
	mz_flood_map(map, map->p_x + 1, map->p_y, i);
	mz_flood_map2(map, map->p_x - 1, map->p_y, i);
	map->c = 'x';
	mz_flood_map(map, map->p_x, map->p_y + 1, i);
	mz_flood_map2(map, map->p_x, map->p_y - 1, i);
	return (mz_zombie_move(map, y, x));
}

void	mz_fix_map(t_map *map)
{
	int	i;
	int	j;

	j = 0;
	while (map->map[j])
	{
		i = 0;
		while (map->map[j][i])
		{
			if (map->map[j][i] <= 47)
				map->map[j][i] = '0';
			i++;
		}
		j++;
	}
}

void	mz_zombie(t_map *map, int count)
{
	int	i;
	int	j;

	j = 0;
	while (map->map[j])
	{
		i = 0;
		while (map->map[j][i])
		{
			if (map->map[j][i] == 'X' || map->map[j][i] == 'W'
				|| map->map[j][i] == 'Y' || map->map[j][i] == 'Z')
			{
				count = mz_zombie_order(map, j, i);
				if (count == 1)
					i++;
				else if (count == 2)
				{
					j++;
					break ;
				}
			}
			i++;
		}
		j++;
	}
}
