
################################################################################
####################			ex03		#########################
####################		By: dexposit		#########################
################################################################################
NAME		=	ex03
CXX			=	clang++
CXXFLAGS	=	-Wall -Werror -Wextra -std=c++98 -I inc -fsanitize=address -g
CXXLFLAGS	=	-L inc -lm
RM			=	rm -rf

SRCS		=	\
			HumanA.cpp	\
			HumanB.cpp	\
			Weapon.cpp	\
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
