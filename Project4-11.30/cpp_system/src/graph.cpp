#include "graph.hpp"
#include "dataHelper.hpp"
#include <algorithm>
#include <iostream>
#include <list>
#include <map>
#include <string>
#include <vector>
#include <queue>
#include <stack>
using std::stack;
using std::queue;
using std::vector;
using std::list;
using std::find;
using std::map;
map<int, vector<int>> allRoute;

void Node::showInfo() const {
  std::cout << "----------------------------" << std::endl;
  std::cout << "The spot's name is " << this->name << std::endl;
  std::cout << "Score: " << this->score << std::endl;
  std::cout << "Description: " << this->description << std::endl;
  std::cout << "----------------------------" << std::endl;
}

Graph::Graph(std::string spotInfoPath, std::string edgeInfoPath) {
  createGraph(spotInfoPath, edgeInfoPath);
} // 注意初始化

void Graph::getRoute(vector<int> que, int sum_score, int sum_time, int limit_time) {
  auto iter_b= que.end();
  iter_b--;
  int top =*iter_b;
  
  bool flag = false;
  for (int i = 0; i < m_vertexNum; i++) {
    if (edges[top][i] != -1 && find(que.begin(),que.end(), i) == que.end()) {
      flag = true;
      if (sum_time + edges[top][i] < limit_time) {
        std::vector<int> temp = que;
        temp.push_back(i);
        getRoute(temp, sum_score + vertex[i].score, sum_time + edges[top][i], limit_time);
      } else {
        for (auto iter = que.begin(); iter != que.end(); iter++)
        allRoute.insert(make_pair(sum_score, que));
        // std::cout << "\nlimit_time2 : " << sum_time << std:: endl;
      }
    }
  }
  if (!flag)
    allRoute.insert(make_pair(sum_score, que));
}

  void Graph::queryAllRoute(const std::string t_start, const int t_time) {
    int start_id = -1;
    for (int i = 0; i < m_vertexNum; i++) {
      if (t_start == vertex[i].name)
        start_id = i;
    }
    if (start_id == -1) {
      std::cout << "输入地点有误，请重新输入" << std::endl;
      return;
    }
    if (t_time <= 0) {
      std::cout << "输入时间有误，请重新输入" << std::endl;
      return;
    }
    vector<int> v;
    v.push_back(start_id);
    getRoute(v, vertex[start_id].score, 0, t_time);
    for (auto i = allRoute.begin(); i != allRoute.end(); i++) {
      std::cout << "总评分 ： " << i->first << " ";
      vector<int> vec = i->second;
      int time = 0, last = -1;
      for (auto iter = vec.begin(); iter != vec.end(); iter++) {
        if (last != -1)
        time += edges[last][*iter];
        auto temp = iter;
        temp++;
        if (temp != vec.end())
        std::cout << vertex[*iter].name << "->";
        else
        std::cout << vertex[*iter].name;
        if (iter != vec.begin())
        last = *iter;
      }
      std::cout << " 总花费时间： " << time << std::endl;
    }
    allRoute.clear();
  }



void Graph::createGraph(std::string spotInfoPath, std::string edgeInfoPath) {
  dataHelper *helper = new dataHelper(spotInfoPath);

  auto spotData = helper->getData();
  m_vertexNum = spotData.size();
  int index = 0;
  for (auto &perNode : spotData) {
    auto info = helper->splitEachInfo(perNode);
    this->vertex[index].id = std::stoi(info[0]);
    this->vertex[index].name = info[1];
    this->vertex[index].score = std::stoi(info[2]);
    this->vertex[index].description = info[3];
    ++index;
  }
  std::cout << "The number of nodes is " << index << std::endl;
  delete helper;

  helper = new dataHelper(edgeInfoPath);
  auto edgesData = helper->getData();
  m_edgeNum = edgesData.size();
  // 初始化边信息
  for (int i = 0; i < this->m_vertexNum; ++i) {
    for (int j = 0; j < this->m_vertexNum; ++j) {
      edges[i][j] = edges[j][i] = -1;
    }
  }
  // 录入边信息
  for (auto &perEdge : edgesData) {
    auto info = helper->splitEachInfo(perEdge);
    // 第一个顶点的id
    int a = std::stoi(info[0]);
    // 第二个顶点的id
    int b = std::stoi(info[1]);
    // 两个定点之间的路径权值（使用的时间）
    int c = std::stoi(info[2]);
    edges[a][b] = edges[b][a] = c;
  }
  for (int i = 0; i < m_vertexNum; i++)
  vertex[i].showInfo();
  delete helper;
}

bool Graph::querySpot(const std::string t_spot_name) const {
  bool visited[MAX];
  // flag用来看它是否已经找到，减少程序开销
  bool flag = false;
  // 初始化visited数组
  for (auto &per : visited) {
    per = false;
  }
  // 防止图出现分块的情况
  for (int i = 0; i < m_vertexNum; ++i) {
    if (!visited[i]) {
      dfsSearch(t_spot_name, i, visited, flag);
    }
  }
  return flag;
}

void Graph::queryRoutes(const std::string t_start,
                        const std::string t_end) const {
  int start_id = -1, end_id = -1;
  for (int i = 0; i < m_vertexNum; i++) {
    if (t_start == vertex[i].name)
      start_id = i;
    if (t_end == vertex[i].name)
      end_id = i;
  }

  if (start_id == -1 || end_id == -1) {
    std::cout << "输入的地点名称有误 请重新输入" << std::endl;
    return;
  }
  list<int> li;
  vector<int> v;
  vector<int> *last = new vector<int>[m_vertexNum];
  v.push_back(start_id);
  while (!v.empty()) {
    int top = v.back();
    bool haveRoute = false;
    for (int i = 0; i < m_vertexNum; i++) {
      if (edges[top][i] != -1 && find(v.begin(), v.end(), i) == v.end() &&
          find(last[top].begin(), last[top].end(), i) == last[top].end()) {
        // 发现有满足条件的点就可以break了，实现深度遍历
        v.push_back(i);
        last[top].push_back(i);
        haveRoute = true;
        if (i == end_id) {
          for (auto &iter : v)
            li.push_back(iter);
          v.pop_back();
        }
        break;
      }
    }
    if (haveRoute == false) {
      v.pop_back();
      last[top].clear();
    }
  }
  int sum = 0;
  // 用map直接实现根据路途时间排序输出
  map<int, std::string> m;
  std::string path;
  for (auto iter = li.begin(); iter != li.end(); iter++) {
    if (*iter != end_id) {
      auto next = iter;
      next++;
      sum += edges[*iter][*next];
      path.append(vertex[*iter].name);
      path.append("->");
    } else {
      path.append(vertex[end_id].name);
      path.append(" 花费时间 : ");
      m.insert(make_pair(sum, path));
      path = "";
      sum = 0;
    }
  }
  for (auto iter = m.begin(); iter != m.end(); iter++) {
    std::cout << "----------------------------------------------------------------------------\n";
    std::cout << iter->second << iter->first << std::endl;
    std::cout << "----------------------------------------------------------------------------\n";
  }
  delete []last;
}
void Graph::dfsSearch(const std::string t_spot_name, int index, bool *visited,
                      bool &flag) const {
  // 递归实现
  // flag用来看它是否已经找到，减少程序开销
  // 终止条件
  if (visited[index])
    return;
  if (flag)
    return;

  // check the node
  if (t_spot_name == vertex[index].name) {
    vertex[index].showInfo();
    flag = true;
  }
  visited[index] = true;

  for (int i = 0; i < m_vertexNum; ++i) {
    if (edges[index][i] != -1) {
      dfsSearch(t_spot_name, i, visited, flag);
    }
  }
}
