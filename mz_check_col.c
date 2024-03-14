/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mz_check_col.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzouine <mzouine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 07:15:51 by mzouine           #+#    #+#             */
/*   Updated: 2024/03/08 20:13:22 by mzouine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	mz_check_col(t_map *map)
{
	int	i;
	int	j;

	j = 0;
	while (map->map[j])
	{
		i = 0;
		while (map->map[j][i])
		{
			if (map->map[j][i] == 'C')
				return (1);
			i++;
		}
		j++;
	}
	return (0);
}
