CXX = g++

CXXFLAGS = -Wall -Wextra -std=c++23

SRC_DIR = src
SRC = $(SRC_DIR)/main.cpp
OBJ = $(SRC:.cpp=.o)

TARGET = main

$(TARGET): $(OBJ)
	$(CXX) $(OBJ) -o $@

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

.PHONY: clean
clean:
	rm -f main
	rm -f src/main
	rm -f src/*.o