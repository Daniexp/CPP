# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dexposit <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/05 16:43:23 by dexposit          #+#    #+#              #
#    Updated: 2023/01/16 13:47:45 by dexposit         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	megaphone
CXX			=	clang++
CXXFLAGS	=	-Wall -Werror -Wextra -std=c++98
RM			=	rm -rf

SRCS			=	megaphone.cpp
SRCDIR		=	./src
OBJDIR		=	./obj

OBJS		=	$(SRCS:%.cpp=%.o)

all:	$(NAME)

$(NAME):	$(OBJS)
	$(CXX) $(CXXFLAGS) -o $(NAME) $^

clean: $(OBJS)
	$(RM) $^

fclean: clean
	$(RM) $(NAME)

re:
	$(RM) $(NAME) $(OBJS)
	make

.PHONY:	 re clean fclean bonus
