
################################################################################
####################			ex03		#########################
####################		By: dexposit		#########################
################################################################################
NAME		=	ex03
CXX			=	c++
CXXFLAGS	=	-Wall -Werror -Wextra -std=c++98 -Wshadow -Wno-shadow -I inc
CXXLFLAGS	=	-L inc -lm
RM			=	rm -rf

SRCS		=	\
			DiamondTrap.cpp	\
			FragTrap.cpp	\
			ScavTrap.cpp	\
			ClapTrap.cpp	\
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
