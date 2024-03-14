# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mzouine <mzouine@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/27 10:42:55 by mzouine           #+#    #+#              #
#    Updated: 2024/03/08 16:52:15 by mzouine          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = main.c get_next_line_utils.c get_next_line.c mz_map_check.c mz_utils.c\
		ft_split.c mz_map_checker.c mz_free_map.c mz_flood_fill.c mz_get_info.c\
		mz_game_launch.c mz_map_print.c mz_mouvement.c mz_check_col.c\
		ft_putnbr.c

SRC_BONUS = bonus/main_bonus.c bonus/get_next_line_utils_bonus.c bonus/get_next_line_bonus.c\
				bonus/mz_map_check_bonus.c bonus/mz_utils_bonus.c bonus/ft_split_bonus.c\
				bonus/mz_map_checker_bonus.c bonus/mz_free_map_bonus.c bonus/mz_flood_fill_bonus.c\
				bonus/mz_get_info_bonus.c bonus/mz_game_launch_bonus.c bonus/mz_map_print_bonus.c\
				bonus/mz_mouvement_bonus.c bonus/mz_check_col_bonus.c bonus/ft_putnbr_bonus.c\
				bonus/mz_texture_fail_bonus.c bonus/mz_lost_bonus.c bonus/mz_zombie_bonus.c\
				bonus/mz_zombie_move.c bonus/ft_itoa.c

OBJS = ${SRC:.c=.o}
OBJS_BONUS = ${SRC_BONUS:.c=.o}
FLAGS = -Wall -Wextra -Werror 
CC = cc
HEADER_BONUS = bonus/so_long_bonus.h
HEADER = so_long.h
RM = rm -f
NAME = so_long
NAME_BONUS = so_long_bonus

all: $(NAME)

%_bonus.o : %_bonus.c  $(HEADER_BONUS)
	$(CC) $(FLAGS) -c $< -o $@

%.o : %.c $(HEADER)
	$(CC) $(FLAGS) -c $< -o $@

$(NAME): $(OBJS)
		$(CC) $(FLAGS) -lmlx -framework OpenGL -framework AppKit $(OBJS) -o $(NAME)

$(NAME_BONUS): $(OBJS_BONUS)
		$(CC) $(FLAGS) -lmlx -framework OpenGL -framework AppKit $(OBJS_BONUS) -o $(NAME_BONUS)

bonus: $(NAME_BONUS)

clean:
	$(RM) $(OBJS) $(OBJS_BONUS)

fclean: clean
		$(RM) $(NAME) $(NAME_BONUS)

re: fclean all

.PHONY: all bonus clean fclean re