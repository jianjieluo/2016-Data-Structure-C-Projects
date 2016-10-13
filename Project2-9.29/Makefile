CC := g++
CXXFLAGS := -Wall -g -std=c++11
INC := -I./include

SRC_DIR := src
BUILD_DIR := build
BIN_DIR := bin
INC_DIR := include

target1 := $(BIN_DIR)/Simulation1
target2 := $(BIN_DIR)/Simulation2
target3 := $(BIN_DIR)/Simulation3
target4 := $(BIN_DIR)/Simulation4
target6 := $(BIN_DIR)/Simulation6

all: $(target1) $(target2) $(target3) $(target4) $(target6)

$(target1) : $(BUILD_DIR)/main1.o $(BUILD_DIR)/Plane.o \
															 $(BUILD_DIR)/Runway.o $(BUILD_DIR)/Random.o
	@mkdir -p data
	@mkdir -p $(BIN_DIR)
	$(CC) $(CXXFLAGS) $^ -o $@

$(target2) : $(BUILD_DIR)/main2.o $(BUILD_DIR)/Plane.o \
															 $(BUILD_DIR)/Runway.o $(BUILD_DIR)/Random.o
	@mkdir -p data
	@mkdir -p $(BIN_DIR)
	$(CC) $(CXXFLAGS) $^ -o $@

$(target3) : $(BUILD_DIR)/main3.o $(BUILD_DIR)/Plane.o \
															 $(BUILD_DIR)/Runway.o $(BUILD_DIR)/Random.o
	@mkdir -p data
	@mkdir -p $(BIN_DIR)
	$(CC) $(CXXFLAGS) $^ -o $@

$(target4) : $(BUILD_DIR)/main4.o $(BUILD_DIR)/Plane.o \
															 $(BUILD_DIR)/Runway.o $(BUILD_DIR)/Random.o
	@mkdir -p data
	@mkdir -p $(BIN_DIR)
	$(CC) $(CXXFLAGS) $^ -o $@

$(target6) : $(BUILD_DIR)/main6.o $(BUILD_DIR)/Plane.o \
															 $(BUILD_DIR)/Runway.o $(BUILD_DIR)/Random.o
	@mkdir -p data
	@mkdir -p $(BIN_DIR)
	$(CC) $(CXXFLAGS) $^ -o $@

# It's a very good example to complie th template class with make !!!!!!
# Since Template is a dynamic distribution,
# So it should be built with the client code(main.cpp) to be the main.o

$(BUILD_DIR)/Random.o : $(SRC_DIR)/Random.cpp
	@mkdir -p $(BUILD_DIR)
	$(CC) $(CXXFLAGS) $(INC) -c $< -o $@

$(BUILD_DIR)/Plane.o : $(SRC_DIR)/Plane.cpp
	@mkdir -p $(BUILD_DIR)
	$(CC) $(CXXFLAGS) $(INC) -c $< -o $@

$(BUILD_DIR)/Runway.o : $(SRC_DIR)/Runway.cpp
	@mkdir -p $(BUILD_DIR)
	$(CC) $(CXXFLAGS) $(INC) -c $< -o $@

$(BUILD_DIR)/main%.o : $(SRC_DIR)/main%.cpp $(SRC_DIR)/Extended_queue.cpp
	@mkdir -p $(BUILD_DIR)
	$(CC) $(CXXFLAGS) $(INC) -c $< -o $@


clean:
	@echo "Cleaning..."
	rm -rf $(BUILD_DIR) $(BIN_DIR)

clearData:
	@echo "Cleaning the data..."
	rm -f data/summary.txt
