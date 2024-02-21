################################################################################
####################			ex02		#########################
####################		By: dexposit		#########################
################################################################################
NAME		=	PmergeMe
TEST_NAME	=	PmergeMe_test
CXX			=	clang++
CXXFLAGS	=	-Wall -Werror -Wextra -std=c++98 -I inc
CXXLFLAGS	=	-L inc -lm
RM			=	rm -rf

SRCS		=	\
    PmergeMe.cpp \
				PmergeMe.cpp \
				main.cpp
TEST_SRCS	=	$(TEST_NAME).cpp
SRCDIR		=	./src/
INCDIR		=	./inc/
TESTDIR		=	./test/
DSRC		=	$(addprefix $(SRCDIR), $(SRCS))
DTESTSRC	=	$(addprefix $(TESTDIR), $(TEST_SRCS))
.SILENT:
OBJS		=	$(DSRC:.cpp=.o)
TEST_OBJS	=	$(DTESTSRC:.cpp=.o)

ifeq ($(MAKECMDGOALS), test)
	SRCS := $(filter-out main.cpp, $(SRCS))
	OBJS := $(filter-out $(SRCDIR)main.o, $(OBJS))
endif

all:	$(NAME)

$(NAME):	$(OBJS)
	$(CXX) -o $(NAME) $(CXXFLAGS) $^

clean:
	$(RM) $(OBJS) $(TEST_OBJS)

fclean:	clean
	$(RM) $(NAME) $(TEST_NAME)
test:	$(OBJS) $(TEST_OBJS)
	$(CXX) -o $(TEST_NAME) $(CXXFLAGS) $^
	./$(TEST_NAME)

re:	fclean all

test_objs: $(TEST_OBJS)

bonus:

.PHONY: all bonus clean fclean re test
