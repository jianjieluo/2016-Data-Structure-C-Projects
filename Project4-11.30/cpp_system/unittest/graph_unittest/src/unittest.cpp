#include <iostream>
#include <string>
#include <vector>
// #include "dataHelper.hpp"
#include "graph.hpp"

int main() {
  auto graph = new Graph("./data/spot.csv", "./data/edgeCar.csv");
  std::string temp;
  std::cout << "Query a node" << std::endl;
  // 通过gdb设置断点的方法测试createGraph方法里面的信息存储是否正确，通过下面代码测试querySApot功能是否正确
  while (std::cin >> temp) {
    if (!graph->querySpot(temp)) {
      std::cout << "no such spot" << std::endl;
    }
    std::cout << "Query a node" << std::endl;
  }
  return 0;
}
