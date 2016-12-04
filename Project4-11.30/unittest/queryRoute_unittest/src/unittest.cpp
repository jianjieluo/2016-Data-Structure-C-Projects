#include <iostream>
#include <string>
#include <vector>
// #include "dataHelper.hpp"
#include "graph.hpp"

int main() {
  auto graph = new Graph("./data/spot.csv", "./data/edgePace.csv");
  std::string start, end;
  // 通过gdb设置断点的方法测试createGraph方法里面的信息存储是否正确，通过下面代码测试querySApot功能是否正确
  std::cin >> start >> end;
  graph->queryRoutes(start, end);
  return 0;
}
