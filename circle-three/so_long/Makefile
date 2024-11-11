# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: akastler <akastler@student.42mulhouse.f    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/11 12:59:02 by event             #+#    #+#              #
#    Updated: 2023/04/05 14:34:08 by akastler         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

SRC = ./core/main.c\
	  ./core/utils/ft_dup_tab.c\
	  ./core/utils/ft_free_tab.c\
	  ./core/utils/ft_init_vars.c\
	  ./core/utils/ft_nb_lines.c\
	  ./core/map_verif/ft_check_map.c\
	  ./core/map_verif/utils/flood_fill.c\
	  ./core/map_verif/utils/ft_check_file.c\
	  ./core/map_verif/utils/ft_get_line_map.c\
	  ./core/map_verif/utils/ft_info_map.c\
	  ./core/map_verif/utils/ft_replace_nl.c\
	  ./core/map_verif/utils/ft_info_map_utils/ft_add_info_map.c\
	  ./core/map_verif/utils/ft_info_map_utils/ft_check_wall.c\
	  ./core/graphics/mlx_main.c\
	  ./core/graphics/ft_end_game.c\
	  ./core/graphics/ft_create_texture.c\
	  ./core/graphics/ft_images.c\
	  ./core/graphics/ft_images2.c\
	  ./core/graphics/ft_moves.c\
	  ./core/graphics/ft_moves2.c\
	  ./core/graphics/ft_anim.c\
	  ./core/graphics/ft_anim2.c\
	  ./core/graphics/ft_move_event.c\
	  ./core/graphics/ft_move_event2.c\
	  ./core/graphics/ft_attack.c\
	  ./core/graphics/ft_find_instance.c\
	  ./core/graphics/ft_break_wall.c\
	  ./core/graphics/ft_place_wall.c\
	  ./core/graphics/ft_torch.c\
	  ./core/graphics/ft_escape.c\
	  

OBJS = ${SRC:.c=.o}

CC = gcc -Wall -Wextra -Werror -fsanitize=address -g3

RM = rm -rf

LIB = ./core/lib/ft_printf/libftprintf.a ./core/lib/get_next_line/gnl.a ./core/lib/libft/libft.a

MLX42 = /Users/$$USER/goinfre/MLX42/build/libmlx42.a -I include -lglfw -L"/Users/$$USER/.brew/opt/glfw/lib/"

MLX42_HOME = /home/chromaxard/MLX42/build/libmlx42.a -Iinclude -ldl -lglfw -pthread -lm

all: ${NAME}

${NAME}:	${OBJS}
	${MAKE} all -C ./core/lib/ft_printf/
	${MAKE} all -C ./core/lib/libft/
	${MAKE} all -C ./core/lib/get_next_line/
	${CC} ${OBJS} ${LIB} ${MLX42} -o ${NAME}

clean:
	${MAKE} clean -C ./core/lib/ft_printf/
	${MAKE} clean -C ./core/lib/libft/
	${MAKE} clean -C ./core/lib/get_next_line/
	${RM} ${OBJS}

fclean: clean
	${MAKE} fclean -C ./core/lib/ft_printf/
	${MAKE} fclean -C ./core/lib/libft/
	${MAKE} fclean -C ./core/lib/get_next_line/
	${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re