#ifndef FAMILYTREE_HPP_
#define FAMILYTREE_HPP_
#include <functional>
#include <vector>
#include "treeNode.hpp"

class familyTree {
 private:
  bool deleteNode(treeNode* t_root);
  treeNode* searchPersonByName(treeNode* t_root, const std::string t_name);

 public:
  familyTree();

  // You need to use the URL to get the infomation of the old data;
  familyTree(const std::string data_path);
  // remember to sync the data when destroy the tree;
  ~familyTree();

  // delete the current node and its subnodes.
  bool deleteNodeByName(const std::string t_name);
  bool insertPersonNode(const std::string t_father_name, treeNode& t_person);
  bool resetPersonWifeInfo(const std::string t_name, personInfo& t_wife);

  treeNode* searchPersonByName(const std::string t_name);
  // You just need to travesal the tree and push the right treeNode printer into
  // a vector
  std::vector<treeNode*> searchPersonByFilter(
      std::function<bool(const treeNode*)> filter);
  int brotherNumber(const std::string t_name);
  // it's a little hard that the node is not the first son of his father
  treeNode* findFather(const std::string t_name);

  int getLivePersonNum() const;
  int getAllPersonNum() const;

  // if we have time, we can use nodejs and construct a web diplay
  void displayTree() const;

  bool readFromFile();
  bool writeToFile();


 private:
  treeNode* m_root;
  bool sync() const;
  std::string m_family_tree_name;
  int m_all_person_num;
  int m_live_person_num;
  std::string m_data_path;
};
#endif
