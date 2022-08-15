
################################################################################
####################     useless_contacts     #########################
################################################################################
NAME	=	useless_contacts
CXX	=	clang++
CXXFLAGS	=	-Wall -Werror -Wextra
CXXLDFLAGS	=	-L inc -lm
RM	=	rm -rf

SRCS	=	useless_contacts.cpp	\
			main.cpp
SRCDIR	=	./src/
INCDIR	=	./inc/
DSRC	=	$(addprefix $(SRCDIR), $(SRCS)) 
.SILENT:
OBJS	=	$(DSRC:.cpp=.o)

all:	$(NAME)

$(NAME):	$(OBJS)
	$(CXX) -o $(NAME) $(CXXFLAGS) $^

clean:
	$(RM) $(OBJS)

fclean:	clean
	$(RM) $(NAME)

re:	fclean $(NAME)

bonus:

.PHONY: all bonus clean fclean re
