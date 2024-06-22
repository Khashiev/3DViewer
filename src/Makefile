CC = g++
FLAGS = -Wextra -Werror -Wall -std=c++17
TEST_LIB = ./tests/*.cc
LINK_FLAGS = -lgtest -lgtest_main -pthread
MODEL = ./model/*.cc
UNAME_S := $(shell uname -s)

clean: 
	rm -rf *.o *.a *.gch *.gcno *.gcda gcov_test s21_test.info ./report ./test

style:
	clang-format -style=google -n model/* tests/*

format:
	clang-format -style=google -i model/* tests/*

test: clean
	$(CC) $(MODEL) ${TEST_LIB} ${LINK_FLAGS} -o test
	./test

valgrind: test
ifeq ($(UNAME_S), Linux) 
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./test
endif

