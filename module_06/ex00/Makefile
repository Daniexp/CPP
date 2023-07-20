
################################################################################
####################			ex00		#########################
####################		By: dexposit		#########################
################################################################################
NAME		=	ex00
CXX			=	clang++
CXXFLAGS	=	-Wall -Werror -Wextra -std=c++98 -I inc -I doctest
CXXLFLAGS	=	-L inc -L ./doctest -lm -ldoctest
RM			=	rm -rf

SRCS		=	\
				main.cpp
SRCDIR		=	./src/
INCDIR		=	./inc/
DSRC		=	$(addprefix $(SRCDIR), $(SRCS))
.SILENT:
OBJS		=	$(DSRC:.cpp=.o)

all:	$(NAME)

$(NAME):	$(OBJS)
	$(CXX) -o $(NAME) $(CXXFLAGS) $^

clean:
	$(RM) $(OBJS)

fclean:	clean
	$(RM) $(NAME)

re:	fclean all

bonus:

.PHONY: all bonus clean fclean re
