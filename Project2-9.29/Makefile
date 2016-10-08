CC := g++
CXXFLAGS := -Wall -g -std=c++11
INC := -I./include

SRC_DIR := src
BUILD_DIR := build
BIN_DIR := bin
INC_DIR := include

$(BIN_DIR)/AirportSimulation : $(BUILD_DIR)/main.o $(BUILD_DIR)/Plane.o \
															 $(BUILD_DIR)/Runway.o
	@mkdir -p $(BIN_DIR)
	$(CC) $(CXXFLAGS) $^ -o $@

# $(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp
# 	@mkdir -p $(BUILD_DIR)
# 	$(CC) $(CXXFLAGS) $(INC) -c $< -o $@

$(BUILD_DIR)/main.o : $(SRC_DIR)/main.cpp $(INC_DIR)/Extended_queue.hpp $(SRC_DIR)/Extended_queue.cpp
	@mkdir -p $(BUILD_DIR)
	$(CC) $(CXXFLAGS) $(INC) -c $< -o $@

$(BUILD_DIR)/Plane.o : $(SRC_DIR)/Plane.cpp
	@mkdir -p $(BUILD_DIR)
	$(CC) $(CXXFLAGS) $(INC) -c $< -o $@

$(BUILD_DIR)/Runway.o : $(SRC_DIR)/Runway.cpp
	@mkdir -p $(BUILD_DIR)
	$(CC) $(CXXFLAGS) $(INC) -c $< -o $@


clean:
	@echo "Cleaning..."
	rm -rf $(BUILD_DIR) $(BIN_DIR)
