# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: akastler <akastler@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/15 09:55:36 by akastler          #+#    #+#              #
#    Updated: 2023/10/10 18:13:53 by akastler         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = Animals

CXX = c++

CXXFLAGS = -Wall -Wextra -Werror -std=c++98

FILES = main Dog.class Cat.class Animal.class WrongAnimal.class WrongCat.class Brain.class

SRCS = $(FILES:=.cpp)

OBJS = ${SRCS:.cpp=.o}

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

debug: $(OBJS)
	$(CXX) $(CXXFLAGS) -fsanitize=address $(OBJS) -o $(NAME)

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re