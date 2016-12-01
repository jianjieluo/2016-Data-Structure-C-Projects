#include "graph.hpp"
#include <cstring>
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
  std::cout << "for debug, the number of nodes" << index << std::endl;
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
    int a = std::stoi(info[0]);
    int b = std::stoi(info[1]);
    int c = std::stoi(info[2]);
    edges[a][b] = edges[b][a] = c;
  }
  delete helper;
}
