#-----------------FLAGS-------------------
CC = gcc
CFL = -Wall -Werror -Wextra -c -std=c11
GCOVFL = -fprofile-arcs -ftest-coverage
CHECKFL = $(shell pkg-config --cflags --libs check)

#-----------------TARGETS-------------------
TRGT = mo_decimal.a
TEST_EXE = test
TEST_EXE_GCOV = test_gcov
OS = $(shell uname -s)

#-----------------SOURCES-------------------
SRC_DIR = .
OBJ_DIR = ./objs
GCOV_DIR = ./gcov
TEST_SRC_DIR = ./tests
TEST_OBJ_DIR = ./tests/objs
SRC = $(shell find $(SRC_DIR) -name "mo_*.c")
TEST_SRC = $(shell find $(TEST_SRC_DIR) -name "*.c")

#-----------------OBJECTS-------------------

OBJS = $(addprefix $(OBJ_DIR)/, $(notdir $(SRC:.c=.o)))
TEST_OBJS = $(addprefix $(TEST_OBJ_DIR)/, $(notdir $(TEST_SRC:.c=.o)))

GCOV_OBJS = $(addprefix $(GCOV_DIR)/, $(notdir $(SRC:.c=.o)))
GCOV_TEST_OBJS = $(addprefix $(GCOV_DIR)/, $(notdir $(TEST_SRC:.c=.o)))

#-----------------CLANG-------------------
CLI = clang-format -i *.c *.h $(TEST_SRC_DIR)/*.c tests_includes/*.h
CLN = clang-format -n *.c *.h $(TEST_SRC_DIR)/*.c tests_includes/*.h
CPPCHK = cppcheck --enable=all --suppress=missingIncludeSystem *.c *.h $(TEST_SRC_DIR)/*.c tests_includes/*.h


all: $(TRGT) test gcov_report
#вернуть обратно цель gcov_report

MK:
	mkdir -p $(OBJ_DIR)
	mkdir -p $(TEST_OBJ_DIR)
	mkdir -p $(GCOV_DIR)


$(TRGT): MK $(OBJS)
	ar rc $(TRGT) $(OBJS)

test: MK $(TRGT) main.o $(TEST_OBJS)
	$(CC) $(TEST_OBJS) $(OBJ_DIR)/main.o $(CHECKFL) -o $(TEST_EXE) -L. $(TRGT)

#удалить запуск test_exe


main.o: main.c
	$(CC) $(CFL) main.c -o $(OBJ_DIR)/main.o

$(OBJS): $(OBJ_DIR)%.o: $(SRC_DIR)%.c mo_decimal.h
	$(CC) $(CFL) -o $@ -c $<

$(TEST_OBJS): $(TEST_OBJ_DIR)%.o: $(TEST_SRC_DIR)%.c tests_includes/mo_tests.h
	$(CC) $(CFL) -o $@ -c $<


gcov_report: MK $(GCOV_OBJS) $(GCOV_TEST_OBJS) main_gcov
	$(CC) $(GCOVFL) $(GCOV_OBJS) $(GCOV_TEST_OBJS) $(GCOV_DIR)/main.o $(CHECKFL) -o $(TEST_EXE_GCOV)
	./$(TEST_EXE_GCOV)
ifeq ($(OS), Linux)
	lcov -t "test_gcov" -o report.info -c -d .
	genhtml -o report report.info
endif


$(GCOV_OBJS): $(GCOV_DIR)%.o: $(SRC_DIR)%.c mo_decimal.h
	$(CC) $(CFL) $(GCOVFL) -o $@ -c $<

$(GCOV_TEST_OBJS): $(GCOV_DIR)%.o: $(TEST_SRC_DIR)%.c tests_includes/mo_tests.h
	$(CC) $(CFL) $(GCOVFL) -o $@ -c $<

main_gcov:
	$(CC) $(CFL) $(GCOVFL) main.c -o $(GCOV_DIR)/main.o	

open:
	open report/index.html
clean:
	rm -rf *.o *.out $(TEST_EXE) $(TEST_EXE_GCOV) *.gcov *.gcno *.gcda *.a *.info
	rm -rf report $(OBJ_DIR) $(TEST_OBJ_DIR) $(GCOV_DIR)

ch: 
	$(CLI)
	$(CLN)
	$(CPPCHK)
