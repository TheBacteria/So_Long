/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mz_map_checker_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzouine <mzouine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 18:12:08 by mzouine           #+#    #+#             */
/*   Updated: 2024/03/08 16:52:49 by mzouine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static	void	mz_error(char **map)
{
	mz_free_map(map);
	ft_putstr_fd("Error\nMap is not valid !", 2);
	exit(1);
}

static void	mz_check_borders(char **map)
{
	unsigned long long	len;
	unsigned long long	width;
	unsigned long long	i;

	len = 0;
	width = 0;
	while (map[0][len])
		len++;
	while (map[width])
	{
		i = 0;
		if (map[width][0] != '1' || map[width][len - 1] != '1')
			mz_error(map);
		while (map[width][i])
			i++;
		if (i != len)
			mz_error(map);
		width++;
	}
	i = 0;
	while (map[0][i++])
	{
		if (map[0][i - 1] != '1' || map[width - 1][i - 1] != '1')
			mz_error(map);
	}
}

static int	mz_map_content(char c, int *p, int *e, unsigned long long *col)
{
	int	player;
	int	exit;

	if (c != '0' && c != '1' && c != 'C' && c != 'E' && c != 'P' && c != 'X')
		return (1);
	if (c == 'C')
		(*col)++;
	else if (c == 'E')
		(*e)++;
	else if (c == 'P')
		(*p)++;
	player = *p;
	exit = *e;
	if (player > 1 || exit > 1)
		return (1);
	return (0);
}

void	mz_map_checker(char **map)
{
	unsigned long long	i;
	unsigned long long	j;
	int					p;
	int					e;
	unsigned long long	col;

	j = 0;
	p = 0;
	col = 0;
	e = 0;
	mz_check_borders(map);
	while (map[j])
	{
		i = 0;
		while (map[j][i])
		{
			if (mz_map_content(map[j][i], &p, &e, &col) == 1)
				mz_error(map);
			i++;
		}
		j++;
	}
	if (p != 1 || e != 1 || col < 1)
		mz_error(map);
}
