CC = g++
CFLAGS = -std=c++17 -Wall -Werror -Wextra
GCOV_FLAGS = -fprofile-arcs -ftest-coverage
TEST_FLAGS = -lgtest -pthread --coverage

FILES := $(shell find . -name '*.cpp' -o -name '*.h')

LIB = brick_game/brickgame.a
GCOV_LIB = gcov_objs/brickgame_gcov.a

GCOV_OBJ_DIR = ./gcov_objs

#all, install, uninstall, clean, dvi, dist, test, gcov_report

all: clean install install_d dist dvi gcov_report

install: brickgame.a brickgame_cli

uninstall: clean

install_d:
	mkdir -p temp
	cd temp && qmake ../gui/desktop && make && mv QtBrickGame ../


brickgame.a:
	mkdir -p objs
	$(CC) $(CFLAGS) -c brick_game/tetris/tetris_model.cpp -o objs/tetris_model.o
	$(CC) $(CFLAGS) -c brick_game/snake/snake_model.cpp -o objs/snake_model.o
	ar rcs $(LIB) objs/*.o


brickgame_cli:
	$(CC) $(CFLAGS) main.cpp gui/cli/brickgame_view.cpp -L. $(LIB) -lncurses -DCLI -o brickgame_cli

runc:
	./brickgame_cli

rund:
	./QtBrickGame

test: brickgame.a
	$(CC) $(CFLAGS) tests/*.cpp -L. $(LIB) $(TEST_FLAGS) -o brickgame_test
	./brickgame_test


gcov_report:
	mkdir -p $(GCOV_OBJ_DIR)
	$(CC) $(CFLAGS) $(GCOV_FLAGS) -c brick_game/tetris/tetris_model.cpp -o $(GCOV_OBJ_DIR)/tetris_model.o
	$(CC) $(CFLAGS) $(GCOV_FLAGS) -c brick_game/snake/snake_model.cpp -o $(GCOV_OBJ_DIR)/snake_model.o
	ar rcs $(GCOV_LIB) $(GCOV_OBJ_DIR)/*.o
	$(CC) $(CFLAGS) -o $(GCOV_OBJ_DIR)/gcov_test tests/*.cpp -L. $(GCOV_LIB) $(TEST_FLAGS) -lgcov
	$(GCOV_OBJ_DIR)/gcov_test
	mkdir -p gcov_report
	lcov --ignore-errors mismatch,mismatch -t "gcov_test" -o gcov_report/test.info -c -d .
	lcov --remove gcov_report/test.info '/usr/*' -o gcov_report/test.info
	lcov --remove gcov_report/test.info '/tests' -o gcov_report/test.info
	lcov --remove gcov_report/test.info 'defines.h' -o gcov_report/test.info
	genhtml -o gcov_report gcov_report/test.info

dvi:
	@doxygen

dist:
	tar -czf tetris.tar.gz brick_game controller gui images tests Doxyfile main.cpp Makefile

openr:
	xdg-open gcov_report/index.html

opend:
	xdg-open documentation/index.html

ch:
	clang-format --style=Google -i $(FILES)
	clang-format --style=Google -n $(FILES)
	#cppcheck --language=c++ --enable=all --suppress=missingIncludeSystem $(FILES)


clean:
	rm -rf objs $(TEST_OBJ_DIR) $(GCOV_OBJ_DIR) temp gcov_report documentation latex $(LIB) brickgame_cli QtBrickGame brickgame_test tetris.tar.gz *.gcda *.gcno


valg:
	valgrind --tool=memcheck --leak-check=yes --track-origins=yes ./tetris