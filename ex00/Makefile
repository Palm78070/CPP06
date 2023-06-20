# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rthammat <rthammat@42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/19 21:28:15 by rthammat          #+#    #+#              #
#    Updated: 2023/06/20 21:42:50 by rthammat         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := ./convert

CXX := c++

CXXFLAGS := -Wall -Werror -Wextra --std=c++98 -g

SRCS := main.cpp \
	ScalarConverter.cpp \

OBJS := $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) $^ -o $@

clean:
	rm -rf *.o *.dSYM

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
