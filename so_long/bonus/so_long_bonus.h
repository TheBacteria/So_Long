/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzouine <mzouine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 15:17:30 by mzouine           #+#    #+#             */
/*   Updated: 2024/03/08 17:58:39 by mzouine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

# include <stdlib.h>
# include <unistd.h> 
# include <signal.h>
# include <fcntl.h>
# include <limits.h>
# include <mlx.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

# define X_EVENT_KEY_PRESS	2
# define X_EVENT_KEY_RELEASE	3
# define X_EVENT_KEY_EXIT	17
# define KEY_W	13
# define KEY_A	0
# define KEY_S	1
# define KEY_D	2
# define KEY_ESC	53

typedef struct map
{
	char	**map;
	int		map_h;
	int		map_w;
	int		p_x;
	int		p_y;
	int		e_x;
	int		e_y;
	void	*mlx;
	void	*win;
	void	*p_img;
	void	*ex_img;
	void	*c_img;
	void	*b_img;
	void	*wall_img;
	void	*x_img;
	void	*w_img;
	void	*y_img;
	void	*z_img;
	int		count;
	int		up;
	int		down;
	int		right;
	int		left;
	int		tmp;
	char	c;
}	t_map;

char	*get_next_line(int fd);
char	*mz_strjoin(char const *s1, char const *s2);
size_t	mz_strlen(const char *s);
int		mz_strchr(const char *s, char c);
size_t	mz_strlcpy(char *dst, char *src, size_t dstsize);
char	*mz_strdup(const char *s1);
size_t	ft_strlen(const char *s);
void	ft_putstr_fd(char *s, int fd);
t_map	mz_map_check(char *s, int map_fd);
char	**ft_split(char const *s, char c);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strdup(const char *s1);
void	mz_map_checker(char **map);
void	mz_free_map(char **map);
void	mz_flood_fill(t_map *map);
void	mz_get_info(t_map *map);
void	mz_game_launch(t_map *map);
void	mz_map_print(t_map *map);
void	mz_up(t_map *map, int x, int y);
void	mz_down(t_map *map, int x, int y);
void	mz_left(t_map *map, int x, int y);
void	mz_right(t_map *map, int x, int y);
int		mz_esc(t_map *map);
int		mz_check_col(t_map *map);
void	ft_putnbr(int i);
void	mz_texture_fail(t_map *map);
void	mz_lost(t_map *map);
void	mz_zombie(t_map *map, int count);
int		mz_zombie_move_up(t_map *map, int y, int x);
int		mz_zombie_move_down(t_map *map, int y, int x);
int		mz_zombie_move_right(t_map *map, int y, int x);
int		mz_zombie_move_left(t_map *map, int y, int x);
int		mz_zombie_move(t_map *map, int y, int x);
void	mz_fix_map(t_map *map);
char	*ft_itoa(int n);

#endif