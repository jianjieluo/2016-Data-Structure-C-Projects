#ifndef FAMILYTREEMANAGER_HPP_
#define FAMILYTREEMANAGER_HPP_
#include "familyTree.hpp"

class familyTreeManager {
 public:
  familyTreeManager();
  ~familyTreeManager();

  // create and delete the trees
  /**
   * use a correct data_path and use its infos to create a tree
   * @param  data_path the family information
   * @return if create successfully, return true;
   */
  bool createFamilyTree(std::string data_path);
  /**
   * delete a whole family tree with the family_name;
   * @param  t_family_name the name of the family need to be delete;
   * @return               if successed, return true;
   */
  bool deleteFamilyTree(std::string t_family_name);

  // statics
  /**
   * get the current family trees in the forest
   * @return the num of the current family trees
   */
  int getFamilyNum() const;
  /**
   * get how many members(all members) are there in a family tree;
   * @param  t_family_tree_name the family tree name;
   * @return                the number of the number of the family.
   */
  int getFamilyMemberNum(std::string t_family_tree_name) const;
  /**
   * get the average Age of a tree live members
   * @param  t_family_tree_name the tree name
   * @return                   the average age
   */
  double getFamilyAverageAge(std::string t_family_tree_name) const;
  // 几代同堂的意思
  int versionsAlive() const;

  // search Person
  treeNode* searchPersonByName(std::string t_name) const;
  std::vector<treeNode*> searchPersonByAge(int t_age) const;
  std::vector<treeNode*> searchPersonByVersion(int t_version) const;
  std::vector<treeNode*> searchFarterAllSon(std::string t_father_name) const;

 private:
  std::vector<familyTree*> m_manager;
  int m_family_num;
};

#endif
