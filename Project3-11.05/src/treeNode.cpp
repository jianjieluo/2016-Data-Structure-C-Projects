#include "treeNode.hpp"
#include <iostream>
using std::cout;
using std::cin;
using std::endl;

treeNode::treeNode() {
  m_version = -1;
  m_info = m_wife = NULL;
  m_first_son = m_next_brother = NULL;
}

treeNode::treeNode(int version, personInfo *info, personInfo *wife,
                   treeNode *firstSon, treeNode *nextBrother) {
  m_version = version;
  setPersonInfo(info);
  setWifeInfo(wife);
  if (firstSon)
    setFirstSon(*firstSon);
  else
    m_first_son = NULL;
  if (nextBrother)
    setNextBrother(*nextBrother);
  else
    m_next_brother = NULL;
}

treeNode::treeNode(treeNode &person) {
  m_version = person.m_version;
  setPersonInfo(person.getPersonInfo());
  setWifeInfo(person.getWifeInfo());
  m_first_son = person.getFirstSon();
  m_next_brother = person.getNextBrother();
}

treeNode::~treeNode() {
  delete m_info;
  delete m_wife;
  // 儿子与兄弟不用删除，因为构造的对象会销毁
}

void treeNode::setVersion(int t_version) { m_version = t_version; }

int treeNode::getVersion() const { return m_version; }

void treeNode::setPersonInfo(const personInfo *t_m_info) {
  if (t_m_info != NULL)
    m_info = new personInfo(t_m_info->age, t_m_info->name, t_m_info->birthday,
                            t_m_info->deathday, t_m_info->fatherName,
                            t_m_info->status);
}

void treeNode::showPersonInfo() const {
  if (m_info == NULL) {
    cout << "Your personal information is empty!" << endl;
    return;
  }
  cout << "--------------------------";
  cout << "\nVersion : " << m_version;
  cout << "\nAge : " << m_info->age;
  cout << "\nName : " << m_info->name;
  cout << "\nBirthday : " << m_info->birthday;
  cout << "\nDeathday : " << m_info->deathday;
  cout << "\nFathername : " << m_info->fatherName;
  cout << "\nStatus : " << (m_info->status ? "Alive" : "Death");
  cout << "\n--------------------------\n";
}

void treeNode::showWifeInfo() const {
  if (m_wife == NULL) {
    cout << "Your wife's information is empty!" << endl;
    return;
  }
  cout << "--------------------------";
  cout << "\nName : " << m_wife->name;
  cout << "\nBirthday : " << m_wife->birthday;
  cout << "\nDeathday : " << m_wife->deathday;
  cout << "\nFathername : " << m_wife->fatherName;
  cout << "\nStatus : " << (m_wife->status ? "Alive" : "Death");
  cout << "\n--------------------------\n";
}

personInfo *treeNode::getPersonInfo() const { return m_info; }

void treeNode::setWifeInfo(const personInfo *t_wife_info) {
  if (t_wife_info != NULL) {
    m_wife = new personInfo(t_wife_info->age, t_wife_info->name,
                            t_wife_info->birthday, t_wife_info->deathday,
                            t_wife_info->fatherName, t_wife_info->status);
  } else {
    m_wife = NULL;
  }
}

personInfo *treeNode::getWifeInfo() const { return m_wife; }

void treeNode::setFirstSon(treeNode &firstSon) {
  if (m_first_son == NULL)
    m_first_son = new treeNode(firstSon);
  else
    m_first_son = &firstSon;
}

void treeNode::setNextBrother(treeNode &nextBrother) {
  if (m_next_brother == NULL)
    m_next_brother = new treeNode(nextBrother);
  else {
    treeNode *bro = m_next_brother;
    while (bro->getNextBrother() != NULL) bro = bro->getNextBrother();
    bro->setNextBrother(nextBrother);
  }
}

treeNode *treeNode::getFirstSon() const { return m_first_son; }

treeNode *treeNode::getNextBrother() { return m_next_brother; }
