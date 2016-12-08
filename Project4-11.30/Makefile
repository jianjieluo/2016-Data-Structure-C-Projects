
bin/main: build/dataHelper.o build/graph.o build/main.o
	@ mkdir -p bin
	g++ -Wall -g -std=c++11 -I./include $^ -o $@

build/%.o: src/%.cpp
	@ mkdir -p build
	g++ -Wall -g -std=c++11 -I./include $^ -o $@ -c

clean:
	rm -rf build/
	rm -rf bin/
