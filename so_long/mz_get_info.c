/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mz_get_info.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzouine <mzouine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 17:58:22 by mzouine           #+#    #+#             */
/*   Updated: 2024/03/08 11:44:45 by mzouine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	mz_analyse(t_map *map, int i, int j)
{
	if (map->map[j][i] == 'P')
	{
		map->p_y = j;
		map->p_x = i;
	}
	else if (map->map[j][i] == 'E')
	{
		map->e_y = j;
		map->e_x = i;
	}
	else
		return ;
}

void	mz_get_info(t_map *map)
{
	int	i;
	int	j;

	j = 0;
	while (map->map[j])
	{
		i = 0;
		while (map->map[j][i])
		{
			if (map->map[j][i] != '1' && map->map[j][i] != '0')
				mz_analyse(map, i, j);
			i++;
		}
		j++;
	}
	map->map_h = j;
	map->map_w = i;
	if (j > 21 || i > 41)
	{
		mz_free_map(map->map);
		ft_putstr_fd("Error\nMap is too big !!\n", 2);
		exit(1);
	}
}
