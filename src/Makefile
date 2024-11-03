CC = g++
FLAGS = -Wextra -Werror -Wall -std=c++17
TEST_LIB = ./tests/*.cc
TEST_MATRIX = ./tests/matrix/*.cc
LINK_FLAGS = -lgtest -lgtest_main -pthread
GCOV_FLAGS=-fprofile-arcs -ftest-coverage
MODEL = ./model/*.cc
UNAME_S := $(shell uname -s)
NAMEAPP = 3D_Viewer_v2

all: install dist

style:
	clang-format -style=google -n *.h *.cc model/* tests/*.cc tests/matrix/*.cc

format:
	clang-format -style=google -i *.h *.cc model/* tests/*.cc tests/matrix/*.cc

test: clean
	$(CC) $(FLAGS) $(MODEL) ${TEST_LIB} ${TEST_MATRIX} ${LINK_FLAGS} -o test
	./test

valgrind: test

ifeq ($(UNAME_S), Linux) 
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./test
endif

install:
	mkdir -p ../build
	cd ../build && qmake ../src/3D_Viewer_v2.pro && make
	cd ../build && rm -rf *.o Makefile *.h .qmake.stash *.cpp

uninstall:
	rm -r ../build

dist:
	mkdir -p ../dist
	cp -R ../build/$(NAMEAPP) ../dist
	cp ../README_RUS.md ../dist && cp ../README.md ../dist
	cd ../dist && tar cvzf $(NAMEAPP)_v1.0.tgz *
	cd ../dist && rm -rf $(NAMEAPP) README.md README_RUS.md
	echo "The build was successfully archived"

dvi:
	open ../README_RUS.md

clean:
	rm -rf *.dSYM *.out *.gcda *.gcno *.info *.gcov *.a *.o *FILE valgrind.txt dvi.log dvi.pdf dvi.aux ./report ./test report readme/index.html ../build ../dist

gcov_report: 
	$(CC) $(FLAGS) $(GCOV_FLAGS) ${TEST_LIB} ${TEST_MATRIX} $(MODEL) ${LINK_FLAGS} -o test
	./test
	gcov --no-output $(TEST_LIB) $(TEST_MATRIX)
	lcov --no-external --capture --directory . --output-file test.info
	genhtml test.info -o report
	open report/index.html
