#include <iostream>
#include <unordered_map>
#include <vector>
#include <stack>
#include <bitset>
#include <functional>

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
typedef vector<bool> visitedNodes;

void DFS(const graph& inputGraph,
	 const int& node,
         visitedNodes& visited,
         function<void(int)> preHook,
         function<void(int)> postHook)
{

  if(preHook)
    preHook(node);

  auto isNotVisited = [visited](int num) { return (visited[num]==false);}; 
  nodes unvisited;
  auto it = inputGraph.find(node);

  auto end = copy_if(it->second.begin(), it->second.end(), unvisited.begin(), isNotVisited);
          	        
  unvisited.resize(std::distance(unvisited.begin(),end));
  for(auto&& destinationNode : unvisited)
  {
     visited[destinationNode]=true;
     DFS(inputGraph,destinationNode,visited,preHook,postHook);
  }

  if(postHook)
      postHook(node);
}

void getFinishTimes(const graph& g,finishTimeStack inputStack)
{
  visitedNodes visited;
  auto addToStack = [&inputStack](int num) { inputStack.push(num);} ;
  for(auto node : g)
  {
      DFS(g,node.first,visited,nullptr,addToStack);
  }
}

void runDFSUsing(const graph& g,finishTimeStack inputStack)
{
   visitedNodes visited;
   auto printConnectedComponents = [](int num) { cout<<num<<" ";};
   
   while(!inputStack.empty())
   {
     int topOfStack = inputStack.top();
     if(visited[topOfStack] == false)
     	DFS(g,inputStack.top(),visited,printConnectedComponents,nullptr);
     inputStack.pop();    
   }
}

graph getTranspose(graph g)
{
   graph newGraph;
   for(auto key: g)
   {
      for(auto value :key.second) 
      {
        auto it = newGraph.insert
		   (std::make_pair(value,std::vector<int>(key.first)));
        if (!it.second)
        it.first->second.push_back(10); 
      }
   } 
   return newGraph;
}

void getStronglyConnectedComponents(graph& g,const int& startNode)
{
   finishTimeStack nodeFinishTimes;
   getFinishTimes(g,nodeFinishTimes);
   graph transpose = getTranspose(g);
   runDFSUsing(transpose,nodeFinishTimes);
}

int main()
{

  return 0;
}
