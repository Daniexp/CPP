
################################################################################
####################			ex01		#########################
####################		By: dexposit		#########################
################################################################################
NAME		=	ex01
CXX			=	c++
CXXFLAGS	=	-Wall -Werror -Wextra -std=c++98 -I inc
CXXLFLAGS	=	-L inc -lm
RM			=	rm -rf

SRCS		=	\
    GradeTooLowException.cpp \
    GradeTooHighException.cpp \
    Form.cpp \
    Bureaucraft.cpp \
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
