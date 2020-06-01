#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>


struct Node 
{
  Node () = default;
  Node (int v, int w) : val(v), weight (w){}
  int val, weight;
};

struct Graph
{
  std::unordered_map <int, std::vector<Node *>> aList;//adjacency list
  bool addEdge (int x, int y, int w);
  //bool removeEdge (int x, int y);
  void bfsTraversal();
  //void dfsTraversal(){}
};

bool Graph::addEdge (int x, int y, int w)//beg, end ,weight
{
  //adds a directional edge
  if (aList.find (x) != aList.end())
  {
    for (auto n : aList[x])
    {
      if (n-> val == y)
        return false; //value already exists
    }
  }
  Node *temp = new Node (y, w);
  aList[x].push_back (temp);
}

void Graph::bfsTraversal()
{
  std::unordered_set <int> visited;
  std::queue <int> toVisit;
  for (auto p: aList)
  {
    if (visited.find(p.first) == visited.end())
    {
      std::cout << p.first << " ";
      toVisit.push(p.first);
    }
  }
  std::cout << std::endl;
}

int main()
{
  return 0;
}
