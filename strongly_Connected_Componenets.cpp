#include <iostream>
#include <unordered_map>
#include <vector>
#include <stack>
#include <bitset>
#include <functional>
#include <algorithm>

using std::cout;
using std::cin;
using std::vector;
using std::unordered_map;
using std::stack;
using std::bitset;
using std::function;

typedef unordered_map<int,vector<int>> graph;
typedef vector<int> nodes;
typedef stack<int> finishTimeStack;
typedef vector<int> visitedNodes;


bool isPresent(std::vector<int> inputVector,int element)
{ 
    bool found = false;
    for(auto&& value : inputVector)
    {
       if(value == element)
        found = true;
    }
    return found;
}


void DFS(graph& inputGraph,
	 int node,
         visitedNodes& visited,
         function<void(int)> preHook,
         function<void(int)> postHook)
{
  visited.push_back(node);
  if(preHook!=nullptr)
    preHook(node);
   
  auto it = inputGraph.find(node);
  for(auto&& destinationNode : it->second)
  {
     if(find(visited.begin(),visited.end(),destinationNode) == visited.end())
     { 
         DFS(inputGraph,destinationNode,visited,preHook,postHook);
     }
  }

  if(postHook!=nullptr)
      postHook(node);
}

void getFinishTimes(graph& g,finishTimeStack& inputStack)
{
  visitedNodes visited;
  auto addToStack = [&inputStack](int num) { inputStack.push(num);} ;
  for(auto& node : g)
  {
    DFS(g,node.first,visited,nullptr,addToStack);
  }
}

vector<vector<int>> runDFSUsing(graph& g,finishTimeStack inputStack)
{
   vector<vector<int>> connectedComponents;
   visitedNodes visited;
   
   while(inputStack.size() != 0)
   {
     vector<int> nodes;
     auto printConnectedComponents = [&nodes](int num) {nodes.push_back(num);};

     int topOfStack = inputStack.top();
     inputStack.pop();    
     if(find(visited.begin(),visited.end(),topOfStack) == visited.end()) {
     	DFS(g,topOfStack,visited,printConnectedComponents,nullptr);
        connectedComponents.push_back(nodes);
     }
   }
   return connectedComponents;
}

void printConnectedComponents(vector<vector<int>> inputVectors)
{
   for(auto&& elem : inputVectors)
   {
      for(auto&& val : elem)
         std::cout<<val;
      std::cout<<"\n";
   }
  
}
graph getTranspose(graph g)
{
   graph newGraph;
   for(auto key: g)
   {
      for(auto value :key.second) 
      {
            vector<int> temp = newGraph[value];
            temp.push_back(key.first);
            newGraph[value] = temp;
      }
   } 
   return newGraph;
}

void printStackContents(finishTimeStack inputStack)
{
   while(inputStack.size()!=0)
   {
      cout<<inputStack.top()<<"\n";
      inputStack.pop();  
   }

}

void PrintGraph(graph g)
{
  for(auto&& pairs : g)
  {
     std::cout<<pairs.first;
     for(auto&& value : pairs.second)
     {
       std::cout<<value<<" ";
     }
     std::cout<<"\n";
  }  
}

vector<vector<int>> getStronglyConnectedComponents(graph& g)
{
   finishTimeStack nodeFinishTimes;
   getFinishTimes(g,nodeFinishTimes);
   graph transpose = getTranspose(g);
   return (runDFSUsing(transpose,nodeFinishTimes));
}


int main()
{
  graph g;
  g[1].push_back(0);
  g[0].push_back(2);
  g[2].push_back(1);
  g[0].push_back(3);
  g[3].push_back(4);
  g.insert(std::make_pair<int,std::vector<int>>(4,std::vector<int>()));
  getStronglyConnectedComponents(g);
  return 0;
}
