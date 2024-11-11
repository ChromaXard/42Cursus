# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: akastler <akastler@student.42mulhouse.f    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/25 15:44:54 by akastler          #+#    #+#              #
#    Updated: 2023/02/07 15:57:08 by akastler         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

SRC = main.c								\
	  ./lib/ft_atoi.c						\
	  ./lib/ft_itoa.c						\
	  ./lib/ft_strchr.c						\
	  ./ft_builds/ft_build_list.c			\
	  ./ft_builds/ft_build_str.c			\
	  ./ft_builds/ft_build_int.c			\
	  ./ft_verifs/ft_verif_int.c			\
	  ./ft_verifs/ft_verif_char.c			\
	  ./ft_verifs/ft_verif_multiple_int.c	\
	  ./ft_verifs/ft_veri_dup.c				\
	  ./ft_list/ft_clear_list.c				\
	  ./ft_list/ft_init.c					\
	  ./ft_list/ft_pushbottom.c				\
	  ./ft_list/ft_pushtop.c				\
	  ./ft_list/ft_deltop.c					\
	  ./ft_list/ft_view_list.c				\
	  ./push_swap_utils/ft_algo.c			\
	  ./push_swap_utils/ft_sort_mid.c		\
	  ./push_swap_utils/ft_indexation.c		\
	  ./push_swap_utils/ft_len_lst.c		\
	  ./push_swap_utils/ft_a.c				\
	  ./push_swap_utils/ft_b.c				\
	  ./push_swap_utils/ft_list_sorted.c	\
	  

OBJS = ${SRC:.c=.o}

CC = gcc

CFLAGS = -Wall -Wextra -Werror

RM = rm -f

all: ${NAME}

${NAME}:	${OBJS}
	${CC} ${CFLAGS} ${OBJS} -o ${NAME}

clean:
	${RM} ${OBJS}

fclean: clean
	${RM} ${NAME}

re: fclean all
	
.PHONY: all clean fclean re