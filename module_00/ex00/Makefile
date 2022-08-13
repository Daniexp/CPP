# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dexposit <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/05 16:43:23 by dexposit          #+#    #+#              #
#    Updated: 2022/08/13 15:11:58 by dexposit         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	megaphone
CXX			=	clang++
CXXFLAGS	=	-Wall -Werror -Wextra
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

re:	fclean all

.PHONY:	 re clean fclean bonus
