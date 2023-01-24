
################################################################################
####################			ex05		#########################
####################		By: dexposit		#########################
################################################################################
NAME		=	harlF
CXX			=	clang++
CXXFLAGS	=	-Wall -Werror -Wextra -I inc
CXXLFLAGS	=	-L inc -lm
RM			=	rm -rf

SRCS		=	\
			HarlF.cpp	\
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
