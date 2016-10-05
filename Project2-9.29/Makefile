CC := g++
CXXFLAGS := -Wall -g -std=c++11
INC := -I./include

SRC_DIR := src
BUILD_DIR := build
BIN_DIR := bin

BIN_DIR/AirportSimulation: BUILD_DIR/main.o BUILD_DIR/%.o
	@mkdir -p BIN_DIR
	$(CC) $(CXXFLAGS) $^ -o $@

BUILD_DIR/%.o: SRC_DIR/%.cpp
	@mkdir -p BUILD_DIR
	$(CC) $(CXXFLAGS) -c $< -o $@

clean:
	@echo "Cleaning..."
	rm -rf $(BUILD_DIR) $(BIN_DIR)
