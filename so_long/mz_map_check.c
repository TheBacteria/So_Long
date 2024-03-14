/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mz_map_check.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzouine <mzouine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 15:27:09 by mzouine           #+#    #+#             */
/*   Updated: 2024/03/08 11:51:06 by mzouine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	mz_extention(char *s, int map_fd)
{
	int	i;

	i = ft_strlen(s);
	if (s[i - 4] == '.' && s[i - 3] == 'b'
		&& s[i - 2] == 'e' && s[i - 1] == 'r')
		return ;
	else
	{
		ft_putstr_fd("Error\nMap extention is not .ber !\n", 1);
		close(map_fd);
		exit(1);
	}
}

static void	mz_empty_line(char *s, int fd_map)
{
	unsigned long long	i;

	i = 0;
	if (!s)
	{
		ft_putstr_fd("Error\nMap is not valid !", 2);
		close(fd_map);
		exit(1);
	}
	while (s[i])
	{
		if (s[0] == '\n'
			|| (s[i] == '\n' && (s[i + 1] == '\n' || s[i + 1] == '\0')))
		{
			close(fd_map);
			free(s);
			ft_putstr_fd("Error\nNew line found !", 2);
			exit(1);
		}
		i++;
	}
}

static char	**mz_map_parser(int map_fd)
{
	char	*line;
	char	*all;
	char	*tmp;
	char	**map;

	line = NULL;
	all = NULL;
	while (1)
	{
		line = get_next_line(map_fd);
		if (line == NULL)
			break ;
		tmp = all;
		all = ft_strjoin(all, line);
		free(line);
		free(tmp);
		if (all == NULL)
			break ;
	}
	tmp = all;
	mz_empty_line(all, map_fd);
	map = ft_split(all, '\n');
	free(all);
	close(map_fd);
	return (map);
}

t_map	mz_map_check(char *s, int map_fd)
{
	t_map	map;

	if (map_fd < 0)
		exit(1);
	mz_extention(s, map_fd);
	map.map = mz_map_parser(map_fd);
	mz_map_checker(map.map);
	mz_flood_fill(&map);
	return (map);
}
