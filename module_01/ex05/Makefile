
################################################################################
####################			ex05		#########################
####################		By: dexposit		#########################
################################################################################
NAME		=	ex05
CXX			=	clang++
CXXFLAGS	=	-Wall -Werror -Wextra -I inc
CXXLFLAGS	=	-L inc -lm
RM			=	rm -rf

SRCS		=	\
			Harl.cpp	\
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
