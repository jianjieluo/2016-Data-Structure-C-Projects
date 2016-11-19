#include "familyTree.hpp"
#include <fstream>
#include <iostream>
#include <sstream>
using namespace std;
bool familyTree::deleteNode(treeNode* t_root) {
    if (t_root == NULL) return false;
    delete t_root;
    return true;
}

treeNode* familyTree::searchPersonByName(treeNode* t_root, const std::string t_name) {
    if (t_root->getPersonInfo()->name == t_name) return t_root;
    treeNode* son = t_root->getFirstSon();
    while (son != NULL) {
        if (son->getPersonInfo()->name == t_name) return son;
        treeNode* bro = son->getNextBrother();
        while (bro != NULL) {
            if (bro->getPersonInfo()->name == t_name)
            return bro;
            bro = bro->getNextBrother();
        }
        son = son->getFirstSon();
    }
    return NULL;
}

familyTree::familyTree() {
    m_root = NULL;
    m_all_person_num = m_live_person_num = 0;
    m_data_path = "";
}

familyTree::familyTree(const string data_path) {
    m_root = NULL;
    m_all_person_num = m_live_person_num = 0;
    m_data_path = data_path;
    sync();
}

familyTree::~familyTree() {

}

bool familyTree::deleteNodeByName(const string t_name) {
    if (searchPersonByName(t_name) == NULL)
    return false;
    return true;
}

bool familyTree::insertPersonNode(const string t_father_name, treeNode& t_person) {
    if (m_root == NULL) {
        m_root = new treeNode(t_person);
        // m_root->showPersonInfo();
        return true;
    }
    treeNode* father = searchPersonByName(t_father_name);
    if (father == NULL)
    return false;
    if (father->getFirstSon() == NULL) {
        father->setFirstSon(t_person); // 应该设定为set
    }
    else {
        treeNode* bro = father->getFirstSon();
        while (bro->getNextBrother() != NULL) {
            bro = bro->getNextBrother();
        }
        bro->setNextBrother(t_person);
    }
    return true;
}

bool familyTree::resetPersonWifeInfo(const string t_name, personInfo& t_wife) {
    treeNode* husband = searchPersonByName(t_name);
    if (husband == NULL)
    return false;
    husband->setWifeInfo(&t_wife);
    return true;
}

treeNode* familyTree::searchPersonByName(const string t_name) {
    treeNode* ptr = m_root;
    while (ptr != NULL) {
        if (ptr->getPersonInfo()->name == t_name)
        return ptr;
        treeNode* brother = ptr->getNextBrother();
        while (brother != NULL) {
            if (brother->getPersonInfo()->name == t_name) {
                return brother;
            }
            brother = brother->getNextBrother();
        }
        ptr = ptr->getFirstSon();
    }
    return NULL;
}

std::vector<treeNode*> familyTree::searchPersonByFilter(std::function<bool(const treeNode*)> filter) {
    std::vector<treeNode*> v;
    treeNode* father = m_root;
    while (father != NULL) {
        if (filter(father)) v.push_back(father);
        treeNode* son = father->getFirstSon();
        while (son != NULL) {
            if (filter(son)) v.push_back(son);
            son = son->getNextBrother();
        }
    }
    return v;
}

int familyTree::brotherNumber(const string t_name) {
    treeNode* ptr = searchPersonByName(t_name);
    if (ptr == NULL)
    return -1;
    int ans;
    while (ptr != NULL) {
        ptr = ptr->getNextBrother();
        ans++;
    }
    return ans;
}

treeNode* familyTree::findFather(const string t_name) {
    treeNode* son = searchPersonByName(t_name);
    if (son == NULL)
    return NULL;
    treeNode* father = m_root;
    while (father != NULL) {
        if (father->getFirstSon() == son) {
            return father;
        }
        treeNode* son_bro = father->getFirstSon()->getNextBrother();
        while(son_bro != NULL) {
            if (son_bro == son) return son_bro;
            son_bro = son_bro->getNextBrother();
        }
    }
    return NULL;
}

int familyTree::getLivePersonNum() const {
    int sum = 0;
    treeNode* ptr = m_root;
    while (ptr != NULL) {
        if (ptr->getPersonInfo()->status == true) sum++;
        treeNode* bro = ptr->getNextBrother();
        while (bro != NULL) {
            if (bro->getPersonInfo()->status == true) sum++;
            bro = bro->getNextBrother();
        }
        ptr = ptr->getFirstSon();
    }
    return sum;
}

int familyTree::getAllPersonNum() const {
    int sum = 0;
    treeNode* ptr = m_root;
    while (ptr != NULL) {
        sum++;
        treeNode* bro = ptr->getNextBrother();
        while (bro != NULL) {
            sum++;
            bro = bro->getNextBrother();
        }
        ptr = ptr->getFirstSon();
    }
    return sum;
}

bool familyTree::readFromFile() {
    ifstream infile;
    infile.open(m_data_path);
//    cout << m_data_path << endl;
//    ifstream s("a.txt", ios_base::app);
    if (!infile.good()) {
        cout << "Open file Failed !" << endl;
        return false;
    }
    int count = 0;
    string sage, sname, sbirthday, sdeathday, sfathername, sstatus;
    while (infile.good()) {
        string s;
        getline(infile, s, '\"');
        if (s == "" || s == "," || s == "\n") continue;
        if (count % 6 == 0) sage = s;
        if (count % 6 == 1) sname = s;
        if (count % 6 == 2) sbirthday = s;
        if (count % 6 == 3) sdeathday = s;
        if (count % 6 == 4) sfathername = s;
        if (count % 6 == 5) { sstatus = s;
            int age;
            stringstream ssage;
            ssage << sage;
            ssage >> age;
            bool status = (sstatus == "true" ? true:false);
            personInfo person(age, sname, sbirthday, sdeathday, sfathername, status);
            treeNode me;
            me.setPersonInfo(&person);
            // me.showPersonInfo();
            insertPersonNode(sfathername, me);
        }
        count++;
        // cout << s << endl;
    }
    // if (m_root == NULL) return true;
    // treeNode* ptr = m_root;
    // while(ptr != NULL) {
    //     ptr->showPersonInfo();
    //     treeNode* bro = ptr->getNextBrother();
    //     while (bro != NULL) {
    //         bro->showPersonInfo();
    //         bro = bro->getNextBrother();
    //     }
    //     ptr = ptr->getFirstSon();
    // }
    infile.close();
    // cout << age << endl;
    // cout << name << endl;
    // cout << birthday << endl;
    // cout << deathday << endl;
    // cout << fathername << endl;
    // cout << status << endl;
    return true;
}
void familyTree::displayTree() const {
    if (m_root == NULL)
        return;
    if (m_root->getPersonInfo() == NULL) {
        cout << "fuck" << endl;
        return;
    }
    treeNode* ptr = m_root;
    while(ptr != NULL) {
        ptr->showPersonInfo();
        treeNode* bro = ptr->getNextBrother();
        while (bro != NULL) {
            bro->showPersonInfo();
            bro = bro->getNextBrother();
        }
        ptr = ptr->getFirstSon();
    }
}
bool familyTree::writeToFile() {
    return true;
}

bool familyTree::sync() const {
    return true;
}

int main() {
    familyTree ft("a.txt");
    ft.readFromFile();
    ft.displayTree();
    return 0;
}