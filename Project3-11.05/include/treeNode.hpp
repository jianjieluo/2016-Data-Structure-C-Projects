#ifndef TREENODE_HPP_
#define TREENODE_HPP_
#include <string>

struct personInfo {
  int age;
  std::string name;      // it is identical
  std::string birthday;  // format (xxxx-xx-xx)
  std::string deathday;  // format (xxxx-xx-xx)
  std::string fatherName;
  bool status;

  personInfo(int _a = 0, std::string _n = "", std::string _b = "",
             std::string _d = "", std::string _f = "", bool _s = true)
      : age(_a),
        name(_n),
        birthday(_b),
        deathday(_d),
        fatherName(_f),
        status(_s) {}

  /**
   * cout the Info in a relative good form
   */
  void showInfo(int version) const;
};

class treeNode {
 public:
  treeNode();
  treeNode(treeNode& person);
  treeNode(int version, personInfo* info, personInfo* wife, treeNode* firstSon,
           treeNode* nextBrother);
  ~treeNode();

  void setVersion(int t_version);
  int getVersion() const;

  void setPersonInfo(const personInfo* t_m_info);
  void showPersonInfo() const;
  personInfo* getPersonInfo() const;

  void setWifeInfo(const personInfo* t_wife_info);
  void showWifeInfo() const;
  personInfo* getWifeInfo() const;

  void setFirstSon(treeNode& firstSon);
  void setNextBrother(treeNode& nextBrother);
  treeNode* getFirstSon() const;
  treeNode* getNextBrother();

 private:
  int m_version;
  personInfo* m_info;
  personInfo* m_wife;
  treeNode* m_first_son;
  treeNode* m_next_brother;
};

#endif
