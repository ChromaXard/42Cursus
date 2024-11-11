# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: akastler <akastler@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/21 14:30:16 by akastler          #+#    #+#              #
#    Updated: 2023/11/22 14:32:50 by akastler         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#name of the executable
NAME = RPN

#files (don't add the .cpp extension)
FILES = main RPN

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
BLACK = \033[0;30m
RED = \033[0;31m
GREEN = \033[0;32m
YELLOW = \033[0;33m
BLUE = \033[0;34m
PURPLE = \033[0;35m
CYAN = \033[0;36m
WHITE = \033[0;37m
RESET = \033[0m

#variables for the progress bar and percentage
COUNT = 1
TOTAL = $(words $(SRCS))
PERCENT = $(shell expr $(COUNT) '*' 100 / $(TOTAL))
MAXSPACE = 20
SPACENEED = $(shell expr $(MAXSPACE) '*' $(PERCENT) / 100)
SPACEMISS = $(shell expr $(MAXSPACE) - $(SPACENEED))

#rules
all: $(NAME)

#.SILENT: is used to hide the compilation commands
.SILENT: $(OBJS) fclean $(NAME) clean re

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@
	@printf "\033[2K\r$(YELLOW)[$(COUNT)/$(TOTAL)]"
	@printf "["
	@printf "\033[7m"
	@printf "%*s" $(SPACENEED) ""
	@printf "\033[27m"
	@printf "%*s" $(SPACEMISS) ""
	@printf "]"
	$(eval PERCENT=$(shell expr $(COUNT) '*' 100 / $(TOTAL)))
	@printf "[$(PERCENT)%%]"
	@printf " Compiling file : $(CYAN)$<  $(RESET)"
	$(eval COUNT=$(shell expr $(COUNT) + 1))
	$(eval PERCENT=$(shell expr $(COUNT) '*' 100 / $(TOTAL)))
	$(eval SPACENEED=$(shell expr $(MAXSPACE) '*' $(PERCENT) / 100))
	$(eval SPACEMISS=$(shell expr $(MAXSPACE) - $(SPACENEED)))

$(NAME): $(OBJS)
	@printf "\033[2K\r$(CYAN)[$(TOTAL)/$(TOTAL)][\033[7m"
	@printf "%*s" $(MAXSPACE) ""
	@printf "\033[27m][100%%] File compilation finished !\n"
	@printf "$(YELLOW)Compiling exec named : $(CYAN)$(NAME)$(RESET)"
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)
	@printf "\033[2K\r$(CYAN)Done ! $(NAME) is ready to use !$(RESET)\n"

clean:
	@printf "$(YELLOW)Cleaning...$(RESET)"
	$(RM) $(OBJS)
	@printf "\033[2K\r$(CYAN)Cleaning done !$(RESET)\n"

fclean:
	@printf "$(YELLOW)FCleaning...$(RESET)"
	$(RM) $(NAME) $(OBJS)
	@printf "\033[2K\r$(CYAN)FCleaning done !$(RESET)\n"

re: fclean all

.PHONY: all clean fclean re