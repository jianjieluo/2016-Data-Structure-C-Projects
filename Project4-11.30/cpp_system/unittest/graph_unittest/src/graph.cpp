#include "graph.hpp"
#include <iostream>
#include <string>
#include "dataHelper.hpp"

void Node::showInfo() const {
  std::cout << "----------------------------" << std::endl;
  std::cout << "The spot's name is " << this->name << std::endl;
  std::cout << "Score: " << this->score << std::endl;
  std::cout << "Description: " << this->description << std::endl;
  std::cout << "----------------------------" << std::endl;
}

Graph::Graph(std::string spotInfoPath, std::string edgeInfoPath) {
  createGraph(spotInfoPath, edgeInfoPath);
}  // 注意初始化

void Graph::createGraph(std::string spotInfoPath, std::string edgeInfoPath) {
  dataHelper* helper = new dataHelper(spotInfoPath);

  auto spotData = helper->getData();
  m_vertexNum = spotData.size();
  int index = 0;
  for (auto& perNode : spotData) {
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
  for (auto& perEdge : edgesData) {
    auto info = helper->splitEachInfo(perEdge);
    // 第一个顶点的id
    int a = std::stoi(info[0]);
    // 第二个顶点的id
    int b = std::stoi(info[1]);
    // 两个定点之间的路径权值（使用的时间）
    float c = std::stof(info[2]);
    edges[a][b] = edges[b][a] = c;
  }
  delete helper;
}

bool Graph::querySpot(const std::string t_spot_name) const {
  bool visited[MAX];
  // flag用来看它是否已经找到，减少程序开销
  bool flag = false;
  // 初始化visited数组
  for (auto& per : visited) {
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

void Graph::dfsSearch(const std::string t_spot_name, int index, bool* visited,
                      bool& flag) const {
  // 递归实现
  // flag用来看它是否已经找到，减少程序开销
  // 终止条件
  if (visited[index]) return;
  if (flag) return;

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
