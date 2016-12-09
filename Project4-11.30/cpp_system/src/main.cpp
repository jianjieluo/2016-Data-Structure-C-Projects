#include <iostream>
#include <string>
#include "graph.hpp"

void help() {
  system("clear");
  std::cout << "The Help List" << '\n';
  std::cout << "---------------------------------" << std::endl;
  std::cout << "0\t: Help list." << std::endl
            << "1\t: Query spot." << std::endl
            << "2\t: Query routes." << std::endl
            << "3\t: Query Routes with limit time" << std::endl;
  std::cout << "---------------------------------" << std::endl;
}

int main() {
  Graph* paceGraph = new Graph("./data/spot.csv", "./data/edgePace.csv");
  Graph* carGraph = new Graph("./data/spot.csv", "./data/edgeCar.csv");
  int choice;
  int method;
  help();
  std::cout << "0 for the pace map and 1 for the car map" << '\n';
  std::cin >> method;
  std::string temp, temp2;
  int t;
  if (method == 0) {
    std::cout << "enter the pace map" << std::endl;
    while (std::cin >> choice) {
      switch (choice) {
        case 0:
          help();
          break;
        case 1:
          std::cout << "The name: ";
          std::cin >> temp;
          paceGraph->querySpot(temp);
          break;
        case 2:
          std::cout << "The name: ";
          std::cin >> temp >> temp2;
          paceGraph->queryRoutes(temp, temp2);
          break;
        case 3:
          std::cin >> temp >> t;
          paceGraph->queryAllRoute(temp, t);
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
        case 3:
          std::cin >> temp >> t;
          carGraph->queryAllRoute(temp, t);
        default:
          std::cout << "invalid input" << '\n';
      }
    }
  }
  return 0;
}
