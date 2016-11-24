#include "familyTreeManager.hpp"
#include <iostream>
#include <string>
#include <vector>
#include "Path.hpp"
using namespace std;
// Constructor
familyTreeManager::familyTreeManager() {
  m_manager = NULL;
  initial = createFamilyTree(Path::familyDataPath);
}

// Distructor
familyTreeManager::~familyTreeManager() { deleteFamilyTree(); }

// Create family tree (load)
bool familyTreeManager::createFamilyTree(string data_path) {
  m_manager = new familyTree(data_path);
  return m_manager->readFromFile();
}

bool familyTreeManager::deleteFamilyTree() {
  bool temp = m_manager->writeToFile();
  delete m_manager;
  return temp;
}

int familyTreeManager::getFamilyMemberNum() const {
  return m_manager->getAllPersonNum();
}

double familyTreeManager::getFamilyAverageAge() const {
  std::vector<treeNode*> v;
  auto getAllLivePeople = [&](const treeNode* temp) {
    return temp->getPersonInfo()->status;
  };
  v = m_manager->searchPersonByFilter(getAllLivePeople);
  int sumOfAge = 0;
  for (std::vector<treeNode*>::iterator i = v.begin(); i != v.end(); ++i) {
    sumOfAge += (*i)->getPersonInfo()->age;
  }
  return sumOfAge * 1.00 / v.size();
}

int familyTreeManager::versionsAlive() const {
  auto getAllLivePeople = [&](const treeNode* temp) {
    return temp->getPersonInfo()->status;
  };
  std::vector<treeNode*> v = m_manager->searchPersonByFilter(getAllLivePeople);
  int versionLow = 1000;
  int versionHigh = -1;
  for (std::vector<treeNode*>::iterator i = v.begin(); i != v.end(); ++i) {
    int tempVersion = (*i)->getVersion();
    if (versionHigh < tempVersion) versionHigh = tempVersion;
    if (versionLow > tempVersion) versionLow = tempVersion;
  }
  return (versionHigh - versionLow + 1);
}

treeNode* familyTreeManager::searchPersonByName(string t_name) const {
  return m_manager->searchPersonByName(t_name);
}

std::vector<treeNode*> familyTreeManager::searchPersonByAge(int t_age) const {
  auto getByAge = [&](const treeNode* temp) {
    return t_age == temp->getPersonInfo()->age;
  };
  return m_manager->searchPersonByFilter(getByAge);
}

std::vector<treeNode*> familyTreeManager::searchPersonByVersion(
    int t_version) const {
  auto getByVersion = [&](const treeNode* temp) {
    return t_version == temp->getVersion();
  };
  return m_manager->searchPersonByFilter(getByVersion);
}

// all his son
std::vector<treeNode*> familyTreeManager::searchFarterAllSon(
    std::string t_father_name) const {
  // find the guy first
  treeNode* t_father = searchPersonByName(t_father_name);
  treeNode* p1 = t_father->getFirstSon();
  std::vector<treeNode*> v;
  while (!p1) {
    v.push_back(p1);
    p1 = p1->getNextBrother();
  }
  return v;
}

void familyTreeManager::printQueryResult(std::vector<treeNode*>& res) {
  // for (auto iter = res.begin(); iter != res.end(); ++iter) {
  //   *(iter)->showPersonInfo();
  // }
  for (const auto& per : res) {
    per->showPersonInfo();
  }
}

// int main() {
//   familyTreeManager t_manager;
//   cout << t_manager.getFamilyMemberNum() << endl;
//   cout << t_manager.getFamilyAverageAge() << endl;
//   cout << t_manager.versionsAlive() << endl;
//   return 0;
// }
