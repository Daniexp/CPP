################################################################################
####################        ex00        #########################
####################    By: dexposit    #########################
################################################################################
NAME        =    ex00
TEST_NAME   =    $(NAME)_test
EXEC_TEST_NAME = $(NAME)_exec_test
CXX         =    clang++
CXXFLAGS    =    -Wall -Werror -Wextra -std=c++98 -I inc
RM          =    rm -rf

SRCS        =    \
    ScalarConvert.cpp \
                main.cpp
TEST_SRCS   =    \
                main_func_test.cpp \
                main_exec_test.cpp

SRCDIR      =    ./src/
TESTDIR     =    ./test/
INCDIR      =    ./inc/
DSRC        =    $(addprefix $(SRCDIR), $(SRCS))
TEST_DSRC   =    $(addprefix $(TESTDIR), $(TEST_SRCS))
.SILENT:
OBJS        =    $(DSRC:.cpp=.o)
TEST_OBJS   =    $(TEST_DSRC:.cpp=.o)

# Variable condicional para compilar main.cpp dependiendo del objetivo
ifeq ($(MAKECMDGOALS), test)
	SRCS := $(filter-out main.cpp, $(SRCS))
	OBJS := $(filter-out $(SRCDIR)main.o, $(OBJS))
endif

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) -o $(NAME) $(CXXFLAGS) $^

clean:
	$(RM) $(OBJS) $(TEST_OBJS)

fclean: clean
	$(RM) $(NAME) $(TEST_NAME) $(EXEC_TEST_NAME) $(TEST_OBJS)

re: fclean all

test: fclean func_test

func_test: $(OBJS) $(TESTDIR)main_func_test.o
	$(CXX) -o $(TEST_NAME) $(CXXFLAGS) $^
	./$(TEST_NAME)

test_objs: $(TEST_OBJS)

$(TESTDIR)%.o: $(TESTDIR)%.cpp
	$(CXX) -c -o $@ $(CXXFLAGS) $<

$(SRCDIR)%.o: $(SRCDIR)%.cpp
	$(CXX) -c -o $@ $(CXXFLAGS) $<

.PHONY: all clean fclean re test func_test
