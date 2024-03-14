# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mzouine <mzouine@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/27 10:42:55 by mzouine           #+#    #+#              #
#    Updated: 2024/03/08 16:35:09 by mzouine          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC_BONUS = main_bonus.c get_next_line_utils_bonus.c get_next_line_bonus.c mz_map_check_bonus.c mz_utils_bonus.c\
		ft_split_bonus.c mz_map_checker_bonus.c mz_free_map_bonus.c mz_flood_fill_bonus.c mz_get_info_bonus.c\
		mz_game_launch_bonus.c mz_map_print_bonus.c mz_mouvement_bonus.c mz_check_col_bonus.c\
		ft_putnbr_bonus.c mz_texture_fail_bonus.c mz_lost_bonus.c mz_zombie_bonus.c mz_zombie_move.c\
		ft_itoa.c

OBJS = ${SRC:.c=.o}
OBJS_BONUS = ${SRC_BONUS:.c=.o}
FLAGS = -Wall -Wextra -Werror -lmlx -framework OpenGL -framework AppKit
CC = cc
HEADER_BONUS = so_long_bonus.h
HEADER = so_long.h
RM = rm -f
NAME = so_long
NAME_BONUS = so_long_bonus

all: $(NAME)

%.o : %.c $(HEADER_BONUS)
	$(CC) $(FLAGS) -c $< -o $@

$(NAME): $(OBJS)
		$(CC) $(FLAGS) $(OBJS) -o $(NAME)

$(NAME_BONUS): $(OBJS_BONUS)
		$(CC) $(FLAGS) $(OBJS_BONUS) -o $(NAME_BONUS)

bonus: $(NAME_BONUS)

clean:
	$(RM) $(OBJS) $(OBJS_BONUS)

fclean: clean
		$(RM) $(NAME) $(NAME_BONUS)

re: fclean all

.PHONY: all bonus clean fclean re