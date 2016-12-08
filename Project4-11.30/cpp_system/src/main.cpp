#include <iostream>
#include <string>
#include "graph.hpp"

void help() {}

int main() {
  help();
  Graph* paceGraph = new Graph("./data/spot.csv", "./data/edgePace.csv");
  Graph* carGraph = new Graph("./data/spot.csv", "./data/edgeCar.csv");
  int choice;
  int method;
  std::cin >> method;
  std::string temp, temp2;
  if (method == 0) {
    std::cout << "enter the pace map" << std::endl;
    while (std::cin >> choice) {
      switch (choice) {
        case 0:
          help();
          break;
        case 1:
          std::cin >> temp;
          paceGraph->querySpot(temp);
          break;
        case 2:
          std::cin >> temp >> temp2;
          paceGraph->queryRoutes(temp, temp2);
          break;
        default:
          std::cout << "invalid input" << '\n';
      }
    }
  } else if (method == 1) {
    std::cout << "enter the car map" << std::endl;
    while (std::cin >> choice) {
      switch (choice) {
        case 0:
          help();
          break;
        case 1:
          std::cin >> temp;
          carGraph->querySpot(temp);
          break;
        case 2:
          std::cin >> temp >> temp2;
          carGraph->queryRoutes(temp, temp2);
          break;
        default:
          std::cout << "invalid input" << '\n';
      }
    }
  }
  return 0;
}
