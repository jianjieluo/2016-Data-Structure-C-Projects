#include "treeNode.hpp"

treeNode::treeNode() {
    m_version = -1;
    m_info = NULL;
    m_wife = NULL;
    m_first_son = NULL;
    m_next_brother = NULL;
}

treeNode::~treeNode() {
    delete m_info;
    delete m_wife;
    
}

void treeNode::setVersion(int t_version) {
    m_version = t_version;
}

int treeNode::getVersion const () {
    return m_version;
}

void treeNode::setPersonInfo(const personInfo& t_m_info) {
    m_info = new personInfo;
    m_info->age = t_m_info.age;
    m_info->name = t_m_info.name;
    m_info->birthday = t_m_info.birthday;
    m_info->deathday = t_m_info.deathday;
    m_info->fatherName = t_m_info.fatherName;
}

void treeNode::showPersonInfor() {
    
}

personInfo* treeNode::getPersonInfo() const {
    return m_info;
}

void treeNode::setWifeInfo(const personInfo& t_wife_info) {
    m_wife = new personInfo;
    m_wife->age =t_wife_info.age;
    m_wife->name =t_wife_info.name;
    m_wife->birthday =t_wife_info.birthday;
    m_wife->deathday =t_wife_info.deathday;
    m_wife->fatherName =t_wife_info.fatherName
}

void treeNode::showWifeInfo() const {
    
}

personInfo* treeNode::getWifeInfo() const {
    return m_wife;
}

treeNode* treeNode::getFirstSon() const {
    return m_first_son;
}

treeNode* treeNode::getNextBrother() const {
    return m_next_brother;
}