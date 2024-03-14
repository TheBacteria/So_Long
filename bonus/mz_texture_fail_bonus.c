/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mz_texture_fail_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzouine <mzouine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 11:49:51 by mzouine           #+#    #+#             */
/*   Updated: 2024/03/08 20:11:21 by mzouine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	mz_texture_fail(t_map *map)
{
	mz_free_map(map->map);
	mlx_destroy_window(map->mlx, map->win);
	ft_putstr_fd("Error\nTexture read error !", 2);
	exit(1);
}
