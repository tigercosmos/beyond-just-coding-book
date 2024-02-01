# Makefile

CXX = g++
CXXFLAGS = -Wall -std=c++11 -g -O0
SRC_DIR = .
BUILD_DIR = .

all: gdb_example1

gdb_example1: $(BUILD_DIR)/main.o $(BUILD_DIR)/foo.o
	$(CXX) $(CXXFLAGS) -o $@ $^

$(BUILD_DIR)/main.o: $(SRC_DIR)/main.cpp $(SRC_DIR)/foo.hpp
	$(CXX) $(CXXFLAGS) -c -o $@ $<

$(BUILD_DIR)/foo.o: $(SRC_DIR)/foo.cpp $(SRC_DIR)/foo.hpp
	$(CXX) $(CXXFLAGS) -c -o $@ $<

clean:
	rm -rf $(BUILD_DIR)/*.o gdb_example1
