################################################################################
####################        ex00        #########################
####################    By: dexposit    #########################
################################################################################
NAME        =    ex00
CXX         =    clang++
CXXFLAGS    =    -Wall -Werror -Wextra -std=c++98 -I inc #-fsanitize=address -g3
RM          =    rm -rf

SRCS        =    \
    ScalarConvert.cpp \
                main.cpp

SRCDIR      =    ./src/
INCDIR      =    ./inc/
DSRC        =    $(addprefix $(SRCDIR), $(SRCS))
OBJS        =    $(DSRC:.cpp=.o)
.SILENT:

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) -o $(NAME) $(CXXFLAGS) $^

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
