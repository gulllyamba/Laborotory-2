CXX = g++

CXXFLAGS = -Wall -Wextra -std=c++23

SRC_DIR = src

UI_DIR = UI

TEST_DIR = tests

INC = $(SRC_DIR)/main.cpp
OBJ = $(INC:.cpp=.o)
TARGET = main

UI = $(SRC_DIR)/$(UI_DIR)/UI.cpp
UI_OBJ = $(UI:.cpp=.o)
UI_TARGET = ui

TEST = $(SRC_DIR)/$(TEST_DIR)/test.cpp
TEST_OBJ = $(TEST:.cpp=.o)
TEST_TARGET = test

$(TARGET): $(OBJ)
	$(CXX) $(OBJ) -o $@

$(UI_TARGET): $(UI_OBJ)
	$(CXX) $(UI_OBJ) -o $@

$(TEST_TARGET): $(TEST_OBJ)
	$(CXX) $(TEST_OBJ) -o $@

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

.PHONY: clean
clean:
	rm -f main
	rm -f main.o
	rm -f ui
	rm -f ui.o
	rm -f src/ui
	rm -f src/*.o
	rm -f src/UI/*.o
	rm -f test
	rm -f test.o
	rm -f src/test
	rm -f src/*.o
	rm -f src/tests/*.o