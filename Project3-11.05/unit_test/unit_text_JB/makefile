main: familyTree.o familyTreeManager.o treeNode.o
	g++ -g -Wall -std=c++11 $^ -o $@

%.o: %.cpp
	g++ -g -Wall -std=c++11 -c $< -o $@
