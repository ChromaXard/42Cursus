# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: akastler <akastler@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/26 17:06:35 by akastler          #+#    #+#              #
#    Updated: 2023/10/05 14:28:14 by akastler         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = Bureaucrat

FILES = main Bureaucrat AForm ShrubberyCreationForm RobotomyRequestForm PresidentialPardonForm

SRCS = $(FILES:=.cpp)

OBJS = $(SRCS:.cpp=.o)

CXX = c++

CXXFLAGS = -Wall -Wextra -Werror -std=c++98

RM = rm -f

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY : all clean fclean re