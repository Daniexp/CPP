
################################################################################
####################			ex02		#########################
####################		By: dexposit		#########################
################################################################################
NAME		=	ex02
CXX			=	clang++
CXXFLAGS	=	-Wall -Werror -Wextra -I inc -std=c++98
CXXLFLAGS	=	-L inc -lm
RM			=	rm -rf

SRCS		=	\
				Account.cpp	\
				tests.cpp
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
