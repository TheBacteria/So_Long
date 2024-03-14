/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzouine <mzouine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 16:29:36 by mzouine           #+#    #+#             */
/*   Updated: 2024/03/10 17:39:11 by mzouine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int ac, char **av)
{
	t_map	map;
	int		i;

	i = 0;
	if (ac != 2)
		return (ft_putstr_fd("Error\nSyntax error: ./so_long \"map\"\n", 1), 1);
	map = mz_map_check(av[1], open(av[1], O_RDONLY));
	mz_game_launch(&map);
	mz_free_map(map.map);
}
