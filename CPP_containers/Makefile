CC = g++
CFLAGS = -Wall -Werror -Wextra --std=c++17
TEST_FLAGS = -lgtest -pthread --coverage
TEST_TARGET = test
SRC_FILES := $(shell find . -name '*.cpp' -o -name '*.h' -o -name '*.tpp')

#-----------------CLANG-------------------
CLI = clang-format --style=Google -i $(SRC_FILES)
CLN = clang-format --style=Google -n $(SRC_FILES)
CPPCHK = cppcheck --language=c++ --enable=all --suppress=missingIncludeSystem *.cpp *.h tests/*.cpp tests/*.h


all: test

test: clean
	$(CC) $(CFLAGS) tests/*.cpp $(TEST_FLAGS) -o $(TEST_TARGET)
	./$(TEST_TARGET)
	geninfo --ignore-errors mismatch,mismatch --rc geninfo_unexecuted_blocks=1 . -o coverage.info
	lcov --remove coverage.info '/usr/*' -o coverage.info
	genhtml coverage.info --output-directory gcov_report

ch:
	$(CLI)
	$(CLN)
	$(CPPCHK)

#	find . -type f \( -name "*.h" -o -name "*.tpp" -o -name "*.cpp" \) -exec clang-format --style=Google -i {} \;
#	find . -type f \( -name "*.h" -o -name "*.tpp" -o -name "*.cpp" \) -exec clang-format --style=Google -n {} \;
#	@find . -type f \( -name "*.h" -o -name "*.tpp" -o -name "*.cpp" \) -exec cppcheck --language=c++ --enable=all --suppress=missingIncludeSystem {} \;

run:
	./$(TEST_TARGET)

open:
	xdg-open gcov_report/index.html

l:
	leaks -atExit -- ./$(TEST_TARGET)

valg:
	valgrind --tool=memcheck --leak-check=yes --track-origins=yes ./$(TEST_TARGET)

val:
	@valgrind --leak-check=full --show-leak-kinds=all ./$(TEST_TARGET)


clean:
	@rm -rf *.o *.a gcov_report/ $(TEST_TARGET) *.info *.gcda *.gcno


