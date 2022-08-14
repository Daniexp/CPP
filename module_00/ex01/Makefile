
################################################################################
####################     useless_contacts     #########################
################################################################################
NAME	=	useless_contacts
CXX	=	clang++
CXXFLAGS	=	-Wall -Werror -Wextra
CXXLFLAGS	=	-Lm -L inc
RM	=	rm -rf

SRCS	=	useless_contacts.cpp	\
			main.cpp
SRCDIR	=	./src
INCDIR	=	./inc
OBJDIR	=	./obj

OBJS	=	$(SRCS:.cpp=.o)

all:	$(NAME)

$(NAME):	$(OBJS)
	$(CXX) $(CXXFLAGS) -o $(NAME) $^

clean:	$(OBJS)
	$(RM) $^

fclean:	clean
	$(RM) $(NAME)

re:	fclean $(NAME)

bonus:

.PHONY: all bonus clean fclean re
