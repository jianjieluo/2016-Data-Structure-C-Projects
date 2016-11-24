#include <iostream>
#include <string>
#include <vector>
#include "familyTreeManager.hpp"
using namespace std;

void help() {
  system("clear");
  std::cout << "Welcome to the Family Tree Manager!" << std::endl;
  std::cout << "------------------------------------" << std::endl;
  std::cout << "0 -> for help" << std::endl;
  std::cout << "1 -> display Tree" << std::endl;
  std::cout << "2 -> getFamilyMemberNum" << std::endl;
  std::cout << "3 -> getFamilyAverageAge" << std::endl;
  std::cout << "4 -> show how many versions are still alive currently"
            << std::endl;
  std::cout << "5 -> search a person by name" << std::endl;
  std::cout << "6 -> search persons by version" << std::endl;
  std::cout << "7 -> get person's all sons" << std::endl;
  std::cout << "8 -> search persons by age" << std::endl;
  std::cout << "------------------------------------" << std::endl;
}

int main() {
  familyTreeManager* manager = new familyTreeManager();
  int choice;
  std::string str1, str2, str3;
  help();
  int temp = -1;
  while (std::cin >> choice) {
    // switch (choice) {
    std::cout << "Please input a command" << std::endl;
    if (choice == 0) {
      // case 0:
      help();
      // break;
    }
    if (choice == 1) {
      // case 1:
      manager->displayTree();
      // break;
    }
    if (choice == 2) {
      // case 2:
      std::cout << "The total number of the current family is "
                << manager->getFamilyMemberNum() << std::endl;
      // break;
    }
    if (choice == 3) {
      // case 3:
      std::cout
          << "The average ages of the living people in the current family is "
          << manager->getFamilyMemberNum() << std::endl;
      // break;
    }
    if (choice == 4) {
      // case 4:
      std::cout << "现在有" << manager->versionsAlive() << "同堂" << std::endl;
      // break;
    }
    if (choice == 5) {
      // case 5:
      std::cout << "Please input the person's name you want to search"
                << std::endl;
      std::cin >> str1;
      treeNode* res = manager->searchPersonByName(str1);
      if (res != NULL) {
        res->showPersonInfo();
      } else {
        std::cout << "no such a person" << std::endl;
      }
      // break;
    }
    if (choice == 6) {
      // case 6:
      std::cout << "Please input the version you want to search" << std::endl;
      std::cin >> temp;
      std::vector<treeNode*> ans1 = manager->searchPersonByVersion(temp);
      if (ans1.empty()) {
        std::cout << "没有符合条件的人！" << std::endl;
      } else {
        manager->printQueryResult(ans1);
      }
      // break;
    }
    if (choice == 7) {
      // case 7:
      std::cout << "Please input the father name" << std::endl;
      std::cin >> str1;
      auto ans2 = manager->searchFarterAllSon(str1);
      if (ans2.empty()) {
        std::cout << "此人没有儿子。。。。" << std::endl;
      } else {
        manager->printQueryResult(ans2);
      }
      // break;
    }
    if (choice == 8) {
      int age;
      std::cin >> age;
      auto ans = manager->searchPersonByAge(age);
      if (ans.empty()) {
        std::cout << "没有符合条件的人！" << std::endl;
      } else {
        manager->printQueryResult(ans);
      }
    }
    if (!(choice >= 0 && choice <= 8)) {
      std::cout << "Invaild Input" << std::endl;
    }
    // break;
    // }
  }
  std::cout << "Good Bye" << std::endl;
  return 0;
}
