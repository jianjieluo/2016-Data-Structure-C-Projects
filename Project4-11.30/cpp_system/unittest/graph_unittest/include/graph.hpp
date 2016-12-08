#ifndef GRAPH_HPP_
#define GRAPH_HPP_

#include <string>
#define MAX 50

struct Node {
  int id;
  std::string name;
  int score;
  std::string description;
  Node(int _id = 0, std::string _n = "", int _s = 0, std::string _d = "")
      : id(_id), name(_n), score(_s), description(_d) {}
  void showInfo() const;
};

typedef Node Vertex;

class Graph {
 private:
  int m_vertexNum;
  int m_edgeNum;
  Vertex vertex[MAX];
  float edges[MAX][MAX];
  // bool visited[MAX];

 public:
  Graph(std::string spotInfoPath, std::string edgeInfoPath);
  ~Graph();
  bool querySpot(const std::string t_spot_name) const;
  void queryRoutes(const std::string t_start, const std::string t_end) const;

  // just for test apoi
  // const Vertex* getVertexs() const { return vertex; }

 private:
  void createGraph(std::string spotInfoPath, std::string edgeInfoPath);
  // 可以复用在其他需要搜索的地方
  void dfsSearch(const std::string t_spot_name, int index, bool* visisted,
                 bool& flag) const;
};

#endif
