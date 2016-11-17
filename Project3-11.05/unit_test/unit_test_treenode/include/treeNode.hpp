#ifndef TREENODE_HPP_
#define TREENODE_HPP_
#include <string>

struct personInfo {
  int age;
  std::string name;      // it is identical
  std::string birthday;  // format (xxxx-xx-xx)
  std::string deathday;  // format (xxxx-xx-xx)
  std::string fatherName;

  personInfo(int _a, std::string _n, std::string _b, std::string _d,
             std::string _f)
      : age(_a), name(_n), birthday(_b), deathday(_d), fatherName(_f) {}

  /**
   * cout the Info in a relative good form
   */
  void showInfo() const;
};

class treeNode {
 public:
  treeNode();
  ~treeNode();

  void setVersion(int t_version);
  int getVersion() const;

  void setPersonInfo();
  void showPersonInfo() const;
  personInfo* getPersonInfo() const;

  void setWifeInfo(const personInfo& t_wife_info);
  void showWifeInfo() const;
  personInfo* getWifeInfo() const;

  treeNode* getFirstSon() const;
  treeNode* getNextBrother() const;

 private:
  int m_version;
  personInfo* m_info;
  personInfo* m_wife;
  treeNode* m_first_son;
  treeNode* m_next_brother;
};

#endif
