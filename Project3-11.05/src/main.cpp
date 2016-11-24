#include <iostream>
#include <string>
#include <vector>
#include "familyTreeManager.hpp"
using namespace std;

void help() {
  system("clear");
  std::cout << "Welcome to the Family Tree Manager!" << std::endl;
  std::cout << "------------------------------------" << std::endl;
  std::cout << "EOF for quit" << std::endl;
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
  std::cout << "9 -> add a person" << std::endl;
  std::cout << "10 -> delete a person" << std::endl;
  std::cout << "11 -> display the tree structure" << std::endl;
  std::cout << "------------------------------------" << std::endl;
}

int main() {
  familyTreeManager* manager = new familyTreeManager();
  int choice;
  std::string str1, str2, str3;
  help();
  int temp = -1;
  personInfo info;
  while (std::cin >> choice) {
    std::cout << "Please input a command" << std::endl;
    if (choice == 0) {
      help();
    }
    if (choice == 1) {
      manager->displayTree();
    }
    if (choice == 2) {
      std::cout << "The total number of the current family is "
                << manager->getFamilyMemberNum() << std::endl;
    }
    if (choice == 3) {
      std::cout
          << "The average ages of the living people in the current family is "
          << manager->getFamilyMemberNum() << std::endl;
    }
    if (choice == 4) {
      std::cout << "现在有" << manager->versionsAlive() << "同堂" << std::endl;
    }
    if (choice == 5) {
      std::cout << "Please input the person's name you want to search"
                << std::endl;
      std::cin >> str1;
      treeNode* res = manager->searchPersonByName(str1);
      if (res != NULL) {
        res->showPersonInfo();
      } else {
        std::cout << "no such a person" << std::endl;
      }
    }
    if (choice == 6) {
      std::cout << "Please input the version you want to search" << std::endl;
      std::cin >> temp;
      std::vector<treeNode*> ans1 = manager->searchPersonByVersion(temp);
      if (ans1.empty()) {
        std::cout << "没有符合条件的人！" << std::endl;
      } else {
        manager->printQueryResult(ans1);
      }
    }
    if (choice == 7) {
      std::cout << "Please input the father name" << std::endl;
      std::cin >> str1;
      auto ans2 = manager->searchFarterAllSon(str1);
      if (ans2.empty()) {
        std::cout << "此人没有儿子。。。。" << std::endl;
      } else {
        manager->printQueryResult(ans2);
      }
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
    if (choice == 9) {
      std::cout << "插入的人的代数";
      int version;
      std::cin >> version;
      std::cout << "生日日期和死亡日期需要以format (xxxx-xx-xx)" << std::endl;
      std::cout << "status 1 代表活着， 0 代表死亡" << std::endl;
      std::cout << "年龄"
                << " "
                << "姓名"
                << " "
                << "生日"
                << " "
                << "死亡日期"
                << " "
                << "父亲名字"
                << " "
                << "是否在世" << std::endl;
      std::cin >> info.age >> info.name >> info.birthday >> info.deathday >>
          info.fatherName >> info.status;
      auto t_treeNode = new treeNode(version, &info, NULL, NULL, NULL);
      if (manager->addPersonNode(info.fatherName, *(t_treeNode))) {
        std::cout << "add person successfully" << std::endl;
      } else {
        std::cout << "add person failed" << std::endl;
      }
    }
    if (choice == 10) {
      std::string name;
      std::cout << "输入需要删除的人的名字" << std::endl;
      std::cin >> name;
      if (manager->deleteNodeByName(name)) {
        std::cout << "Delete Successfully" << std::endl;
      } else {
        std::cout << "Delete failed" << std::endl;
      }
    }
    if (choice == 11) {
      std::cout << "The structure of the tree is:" << std::endl;
      manager->displayStructure();
    }
    if (!(choice >= 0 && choice <= 11)) {
      std::cout << "Invaild Input" << std::endl;
    }
  }
  manager->deleteFamilyTree();
  std::cout << "Good Bye" << std::endl;
  return 0;
}
