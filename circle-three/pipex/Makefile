# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: event <event@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/11 11:49:46 by event             #+#    #+#              #
#    Updated: 2023/03/11 12:16:55 by event            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex

SRC = ./core/main.c\
	  ./core/lib/ft_calloc.c\
	  ./core/lib/ft_split.c\
	  ./core/lib/ft_strjoin.c\
	  ./core/lib/ft_strlen.c\
	  ./core/lib/ft_strncmp.c\
	  ./core/pipex/main_pipex.c\
	  ./core/pipex/childs/child_one.c\
	  ./core/pipex/childs/child_two.c\
	  ./core/pipex/childs/functions/free_list_path.c\
	  ./core/pipex/childs/functions/ft_exec_this.c\
	  ./core/pipex/childs/functions/ft_give_correct_path.c\

OBJS = ${SRC:.c=.o}

CC = gcc -Wall -Wextra -Werror -g3

RM = rm -rf

CREAT = touch

all: ${NAME}

${NAME}:	${OBJS}
	${CC} ${OBJS} -o ${NAME}

debug:	${OBJS}
	${CC} -fsanitize=address ${OBJS} -o ${NAME}

test:
	${CREAT} test1.txt
	echo "Bonjour, je suis un fichier de test." > test1.txt
	${CREAT} test2.txt

test_clean:
	${RM} test1.txt
	${RM} test2.txt

clean:
	${RM} ${OBJS}

fclean: clean
	${RM} ${NAME}

re: fclean all

.PHONY: all debug test test_clean clean fclean re