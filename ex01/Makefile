# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rthammat <rthammat@42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/25 17:27:23 by rthammat          #+#    #+#              #
#    Updated: 2023/06/25 17:55:16 by rthammat         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME := ./serialization

CXX := c++

CXXFLAGS := -Wall -Werror -Wextra --std=c++98 -g

SRCS := main.cpp \
	Serializer.cpp \

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
