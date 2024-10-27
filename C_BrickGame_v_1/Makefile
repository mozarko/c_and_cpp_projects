CC = gcc
CFLAGS = -std=c11 -Wall -Werror -Wextra -Wpedantic
GCOV_FLAGS = -fprofile-arcs -ftest-coverage
CHECKFL = $(shell pkg-config --cflags --libs check ncurses)
#GCOV_LIB_FL = -lcheck -lsubunit -lncurses -lm -lgcov

FILES := $(shell find . -name '*.c' -o -name '*.h')

LIB = brick_game/tetris/tetris.a
GCOV_LIB = gcov_objs/tetris_test.a

OBJ_DIR = ./objs
TEST_OBJ_DIR = ./tests/objs
GCOV_OBJ_DIR = ./gcov_objs

#all, install, uninstall, clean, dvi, dist, test, gcov_report

all: clean dist install test gcov_report dvi

install: tetris.a tetris

uninstall: clean

tetris.a:
	mkdir -p objs
	$(CC) $(CFLAGS) -c brick_game/tetris/src/fsm.c -o objs/fsm.o
	$(CC) $(CFLAGS) -c brick_game/tetris/src/tetris_backend.c -o objs/tetris_backend.o
	$(CC) $(CFLAGS) -c brick_game/tetris/src/objects.c -o objs/objects.o
	$(CC) $(CFLAGS) -c gui/cli/tetris_frontend.c -o objs/tetris_frontend.o
	ar rcs $(LIB) objs/*.o


tetris:
	$(CC) $(CFLAGS) -c main.c -o objs/main.o
	$(CC) $(CFLAGS) -o tetris objs/main.o -L. $(LIB) -lncurses

run:
	./tetris

test: tetris.a
	mkdir -p $(TEST_OBJ_DIR)
	$(CC) $(CFLAGS) -c tests/tests.c -o $(TEST_OBJ_DIR)/tests.o
	$(CC) $(CFLAGS) -c tests/tetris_tests.c -o $(TEST_OBJ_DIR)/tetris_test.o
	$(CC) $(CFLAGS) -o tetris_test $(TEST_OBJ_DIR)/tests.o $(TEST_OBJ_DIR)/tetris_test.o -L. $(LIB) $(CHECKFL)
	./tetris_test


gcov_report:
	mkdir -p $(GCOV_OBJ_DIR)
	$(CC) $(CFLAGS) $(GCOV_FLAGS) -c brick_game/tetris/src/fsm.c -o $(GCOV_OBJ_DIR)/fsm.o
	$(CC) $(CFLAGS) $(GCOV_FLAGS) -c brick_game/tetris/src/tetris_backend.c -o $(GCOV_OBJ_DIR)/tetris_backend.o
	$(CC) $(CFLAGS) $(GCOV_FLAGS) -c brick_game/tetris/src/objects.c -o $(GCOV_OBJ_DIR)/objects.o
	$(CC) $(CFLAGS) $(GCOV_FLAGS) -c gui/cli/tetris_frontend.c -o $(GCOV_OBJ_DIR)/tetris_frontend.o
	ar rcs $(GCOV_LIB) $(GCOV_OBJ_DIR)/*.o
	$(CC) $(CFLAGS) -o gcov_test tests/tests.c tests/tetris_tests.c -L. $(GCOV_LIB) $(CHECKFL) -lgcov
	./gcov_test
	mkdir -p gcov_report
	lcov -t "gcov_test" -o gcov_report/test.info -c -d .
	lcov --remove gcov_report/test.info 'gui/cli/tetris_frontend.c' -o gcov_report/test.info
	genhtml -o gcov_report gcov_report/test.info

dvi:
	@doxygen

dist:
	tar -czf tetris.tar.gz brick_game gui Doxyfile main.c Makefile tests

openr:
	xdg-open gcov_report/index.html

opend:
	xdg-open documentation/index.html

ch:
	clang-format --style=Google -i $(FILES)
	clang-format --style=Google -n $(FILES)
	cppcheck --enable=all --suppress=missingIncludeSystem $(FILES)


clean:
	rm -rf $(OBJ_DIR) $(TEST_OBJ_DIR) $(GCOV_OBJ_DIR) gcov_report documentation latex $(LIB) tetris tetris_test gcov_test tetris.tar.gz


valg:
	valgrind --tool=memcheck --leak-check=yes --track-origins=yes ./tetris_test