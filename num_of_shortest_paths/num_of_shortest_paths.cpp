
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <unordered_map>
#include <queue> 
#include <utility>
#include <functional>
#include "limits.h"

using namespace std;

class Node
{
private:
  int num;
  bool visited;
  unsigned int numOfPaths;
  int level;
public:
  Node() {}
  Node(const Node &n1)
  {
    this->num = n1.getName();
    this->visited = n1.isVisited();
    this->numOfPaths = n1.GetNumOfPaths();
    this->level = n1.getLevel();
  }
  Node(int n)
  {
    num = n;
    visited=false;
    numOfPaths=0;
    level=INT_MAX;
  }
  void markVisited()
  {
    visited=true;
  }
  bool isVisited() const
  {
    return (visited==true);
  }
  void SetNumOfPaths(int n)
  {
    numOfPaths = n;
  }

  int GetNumOfPaths() const
  {
    return numOfPaths;
  }

  int getName() const
  {
    return num;
  }

  bool operator == (const Node &n1)
  {
    return (this->num == n1.num);
  }

  int getLevel() const
  {
    return this->level;
  }

  void setLevel(int level)
  {
    this->level = level;
  }

};

struct hash_name {
  size_t operator() ( const Node & givenNode) const
    {	
        return hash<int>()(givenNode.getName());
    }
};

struct node_compare {
  bool operator() (const Node &n1, const Node &n2) const
  {	
    return (n1.getName() == n2.getName());
  }
};


class Graph
{
private:
  unordered_map<Node,vector<Node>,hash_name,node_compare> adjList;
  void updateNode(Node oldNode,Node newNode)
  {
 
  }
public:
  void AddEdge(Node src,Node dst)
  {
    if (src==dst)
      {
        return;
      }
    if(adjList.find(src)!= adjList.end()
       &&
       (find(adjList[src].begin(),adjList[src].end(),dst)) != adjList[src].end())
      {
        return;
      }
    else if(adjList.find(src) != adjList.end())
      {
        adjList[src].push_back(dst);
      }
    else
      {
        vector<Node> temp={dst};
        adjList.insert(make_pair(src,temp));
      }
    AddEdge(dst,src);
  }

  int GetNumOfShortestPath(Node src,Node dst)
  {
    if(adjList.find(src) != adjList.end())
      {
        queue<Node> bfsQueue;
        bfsQueue.push(src);
        int levelCount = 0;
        while(! bfsQueue.empty())
          {
            Node presentNode = bfsQueue.front();
            bfsQueue.pop();
            for(auto&& dstNode : adjList.at(presentNode))
              {
                if(dstNode.getName() == dst.getName()
                   &&
                   dstNode.getLevel() <= dst.getLevel())
                  {
                    int newCount = dstNode.GetNumOfPaths() + presentNode.GetNumOfPaths() + 1;
                    dstNode.SetNumOfPaths(newCount);
                    dstNode.setLevel(dst.getLevel());
                    updateNode(presentNode,dstNode);
                  }
                else if(dstNode.isVisited()
                        &&
                        dstNode.getLevel() <= dst.getLevel())
                  {
                    int newCount = dstNode.GetNumOfPaths() + presentNode.GetNumOfPaths() + 1;
                    dstNode.SetNumOfPaths(newCount);
                  }
                else
                  {
                    dstNode.markVisited();
                    int newCount = presentNode.GetNumOfPaths() + 1;
                    dstNode.SetNumOfPaths(newCount);
                    dstNode.setLevel(levelCount);
                    bfsQueue.push(dstNode);
                  }
              }
            ++levelCount;
          }
        return dst.GetNumOfPaths();
      }
    return 0;
  }

  void PrintGraph()
  {
    for(auto&& src : adjList)
      {
        cout<<"src:" <<src.first.getName();
        for(auto&& dst : src.second)
          {
            cout<<"dst: "<<dst.getName()<<"-->";
          }
        cout<<"\n";
      }
  }
};

int main()
{
  
  Node n1(1);
  Node n2(2);
  Node n3(3);

  Graph G;
  G.AddEdge(n1,n2);
  G.AddEdge(n2,n3);
  G.AddEdge(n1,n3);

  G.PrintGraph();

  cout<<G.GetNumOfShortestPath(n1,n2);
  return 0;
}
