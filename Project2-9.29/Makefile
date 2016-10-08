CC := g++
CXXFLAGS := -Wall -g -std=c++11
INC := -I./include

SRC_DIR := src
BUILD_DIR := build
BIN_DIR := bin
INC_DIR := include

$(BIN_DIR)/AirportSimulation : $(BUILD_DIR)/main.o $(BUILD_DIR)/Plane.o $(BUILD_DIR)/Runway.o $(BUILD_DIR)/Extended_queue.o
	@mkdir -p $(BIN_DIR)
	$(CC) $(CXXFLAGS) $(INC) $^ -o $@

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(BUILD_DIR)
	$(CC) $(CXXFLAGS) $(INC) -c $< -o $@

$(BUILD_DIR)/Extended_queue.o : $(INC_DIR)/Extended_queue.cpp $(INC_DIR)/Extended_queue.tcc
	@mkdir -p $(BUILD_DIR)
	$(CC) $(CXXFLAGS) $(INC) -c $< -o $@

clean:
	@echo "Cleaning..."
	rm -rf $(BUILD_DIR) $(BIN_DIR)
