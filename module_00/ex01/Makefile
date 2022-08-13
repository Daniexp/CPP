
################################################################################
####################     useless_contacts     #########################
################################################################################
NAME	=	useless_contacts
CXX	=	clang++
CXXFLAGS	=	-Wall -Werror -Wextra
CXXLFLAGS	=	-L inc -lm
RM	=	rm -rf

SRCS	=	useless_contacts.cpp
SRCDIR	=	./src
INCDIR	=	./inc
OBJDIR	=	./obj

OBJS	=	$(SRCS:%cpp=%.o)

all:	$(NAME)

$(NAME):	$(OBJS)
	$(CXX) $(CXXFLAGS) -o $(NAME) $^

clean:	$(OBJS)
	$(RM) $^

fclean:	clean
	$(RM) $(NAME)

re:	fclean all

bonus:

.PHONY: bonus clean fclean re
