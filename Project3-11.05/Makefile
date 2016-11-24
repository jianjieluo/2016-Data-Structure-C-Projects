CC := g++
CXXFLAGS := -Wall -g -std=c++11
INC := -I./include

target1 := bin/Family
all : $(target1)

$(target1) : build/familyTree.o build/familyTreeManager.o build/treeNode.o
	@mkdir -p bin
	$(CC) $(CXXFLAGS) $(INC) src/main.cpp $^ -o $@

build/%.o: src/%.cpp
	@mkdir -p build
	$(CC) $(CXXFLAGS) $(INC) -c $< -o $@

clean:
	@echo "Cleaning..."
	rm -rf build/
	rm -rf bin/
