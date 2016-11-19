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
  if (t_wife_info != NULL)
    m_wife = new personInfo(t_wife_info->age, t_wife_info->name,
                            t_wife_info->birthday, t_wife_info->deathday,
                            t_wife_info->fatherName, t_wife_info->status);
}

personInfo *treeNode::getWifeInfo() const { return m_wife; }

//  这个需不需要考虑它会不会出现儿子是别人的问题
void treeNode::setFirstSon(treeNode &firstSon) {
  m_first_son = new treeNode(firstSon);
}

void treeNode::setNextBrother(treeNode &nextBrother) {
  if (m_next_brother == NULL)
    m_next_brother = new treeNode(nextBrother);
  else {
    // cout << "hello" << endl;
    treeNode *bro = m_next_brother;
    while (bro->getNextBrother() != NULL)
      bro = bro->getNextBrother();
    bro->setNextBrother(nextBrother);
    // nextBrothershowPersonInfo();
  }
}

treeNode *treeNode::getFirstSon() const { return m_first_son; }

treeNode *treeNode::getNextBrother() { return m_next_brother; }

// int main() {
// 	treeNode me;
// 	personInfo m(18, "Zeongwan", "2012-01-01", "2100-02-02", "siwu", true);
// 	personInfo m_wife(18, "wy", "2012-02-01", "2100-01-02", "dont know",
// true);
// 	me.setPersonInfo(&m);
// 	me.setWifeInfo(&m_wife);
// 	// me.showPersonInfo();
// 	// me.showWifeInfo();

// 	// treeNode son;
// 	// personInfo m_son(10, "dont", "2020-01-02", "2200-01-02", "Zeongwan",
// true);
// 	// son.setPersonInfo(m_son);
// 	// me.setFirstSon(son);
// 	// me.getFirstSon()->showPersonInfo();

// 	treeNode brother;
// 	personInfo m_bro(20, "Zhoufeng", "2012-02-02", "2100-12-02", "Zhouwu",
// true);
// 	brother.setPersonInfo(&m_bro);
// 	me.setNextBrother(brother);
// 	me.getNextBrother()->showPersonInfo();

// 	treeNode brother2;
// 	personInfo m_bro2(20, "Zhoufeng2", "2012-02-02", "2100-12-02", "Zhouwu",
// true);
// 	brother2.setPersonInfo(&m_bro2);
// 	me.setNextBrother(brother2);
// 	me.getNextBrother()->getNextBrother()->showPersonInfo();

// 	return 0;
// }
