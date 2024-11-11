# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: akastler <akastler@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/11 17:44:44 by akastler          #+#    #+#              #
#    Updated: 2023/10/17 17:57:01 by akastler         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#name of the executable
NAME = convert

#files (don't add the .cpp extension)
FILES = main Base

#modification of files variables to add .cpp extension
SRCS = $(FILES:=.cpp)

#modification of srcs variables to add .o extension
OBJS = $(SRCS:.cpp=.o)

#compiler and flags
CXX = c++

CXXFLAGS = -Wall -Wextra -Werror -std=c++98

#utils
RM = rm -f

#colors
YELLOW = \033[0;33m
BLUE = \033[0;34m
RESET = \033[0m

#.SILENT: is used to hide the compilation commands
.SILENT:

#rules
all: $(NAME)

$(NAME): $(OBJS)
	@echo "$(YELLOW)Compiling...$(RESET)"
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)
	@echo "$(BLUE)Done ! $(NAME) is ready to use !$(RESET)"

clean:
	@echo "$(YELLOW)Cleaning...$(RESET)"
	$(RM) $(OBJS)
	@echo "$(BLUE)Done !$(RESET)"

fclean:
	@echo "$(YELLOW)FCleaning...$(RESET)"
	$(RM) $(NAME) $(OBJS)
	@echo "$(BLUE)Done !$(RESET)"

re: fclean all

.PHONY: all clean fclean re