FLAGS=-std=c++11 -g
BUILD_DIR=./build

all:
	mkdir -p $(BUILD_DIR)
	g++ $(FLAGS) -o $(BUILD_DIR)/run_sorts src/main.cpp
