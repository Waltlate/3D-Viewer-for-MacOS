.PHONY: all install uninstall clean dvi dist test check_mk gcov_report install_lcov brew lcov style_check style clang valgrind

CC = g++ -std=c++17 -g
FLAGS = -Wall -Wextra -Werror

FLAGS_TEST = -coverage -lgtest -lgtest_main -pthread
PROJECT = $(shell pwd)
SOURCE_BUILD = 3d_viewer_my
SOURCES = 3d_viewer_my/model/model.cc
TEST_FILE = test/tests.cc
TEST_OUT = tests
INSTALL_FOLDER = Viewer

all: install dvi

install: uninstall
	mkdir ../../$(INSTALL_FOLDER)
	cd ../../$(INSTALL_FOLDER) && cmake $(PROJECT)/$(SOURCE_BUILD)/. -B . && cmake --build .

uninstall: 
	rm -rf ../../$(INSTALL_FOLDER)

dvi:
	open -a "Google Chrome" manual.html

dist: cleandist install
	cd ../../ && tar -cvf s21_viewer.tar.gz $(INSTALL_FOLDER)

cleandist:
	rm -rf ../../s21_viewer.tar.gz

clean:
	rm -rf ./$(TEST_OUT) *.gcno *.gcda *.a *.o report

test: clean 
	g++ $(SOURCES) $(TEST_FILE) $(FLAGS_TEST) -o $(TEST_OUT)
	./$(TEST_OUT)

gcov_report: test
	mkdir report
	gcovr -r .. --html --html-details -o report/index.html
	# lcov --no-external --directory ./ --capture --output-file report.info
	# genhtml report.info --output-directory report
	rm -rf *.gcno *.info *.gcda
	open report/index.html

style_check: clang
	# clang-format -n $(SOURCE_BUILD)/*.h $(SOURCE_BUILD)/*.cc
	find . -type f -name ".h" -o -name "*.cc" | xargs clang-format -style=Google -n

style: clang
	# clang-format -i $(SOURCE_BUILD)/*.h $(SOURCE_BUILD)/*.cc
	find . -type f -name ".h" -o -name "*.cc" | xargs clang-format -style=Google -i
	
clang:
ifeq ("","$(wildcard ./.clang-format)")
	cp -f ../materials/linters/.clang-format ./.clang-format
endif

valgrind:
	g++ $(SOURCES) $(TEST_FILE) $(FLAGS_TEST) -o $(TEST_OUT)
	CK_FORK=no valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./$(TEST_OUT)
