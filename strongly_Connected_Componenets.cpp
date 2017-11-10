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

void DFS(graph& inputGraph,
	 int node,
         visitedNodes& visited,
         function<void(int)> preHook,
         function<void(int)> postHook)
{

  if(preHook!=nullptr)
    preHook(node);

  auto isNotVisited = [visited](int num) { return (visited.at(num)==false);}; 
  nodes unvisited(1000000);
  auto it = inputGraph.find(node);

  auto end = copy_if(it->second.begin(), it->second.end(), unvisited.begin(), isNotVisited);
          	        
  unvisited.resize(std::distance(unvisited.begin(),end));
  for(auto&& destinationNode : unvisited)
  {
     visited[destinationNode]=true;
     DFS(inputGraph,destinationNode,visited,preHook,postHook);
  }

  if(postHook!=nullptr)
      postHook(node);
}

void getFinishTimes(graph& g,finishTimeStack& inputStack)
{
  visitedNodes visited(100000);
  auto addToStack = [&inputStack](int num) { inputStack.push(num);} ;
  for(auto& node : g)
  {
      DFS(g,node.first,visited,nullptr,addToStack);
  }
}

void runDFSUsing(graph& g,finishTimeStack inputStack)
{
   visitedNodes visited;
   auto printConnectedComponents = [](int num) { cout<<num<<" ";};
   
   while(!inputStack.empty())
   {
     int topOfStack = inputStack.top();
     if(visited[topOfStack] == false)
     	DFS(g,topOfStack,visited,printConnectedComponents,nullptr);
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

void getStronglyConnectedComponents(graph& g)
{
   finishTimeStack nodeFinishTimes;
   getFinishTimes(g,nodeFinishTimes);
   //graph transpose = getTranspose(g);
   //runDFSUsing(transpose,nodeFinishTimes);
}

int main()
{
  graph g;
  g[1].push_back(0);
  g[0].push_back(2);
  g[2].push_back(1);
  g[0].push_back(3);
  g[3].push_back(4);
  for(auto&& pairs : g)
  {
     std::cout<<pairs.first;
     for(auto&& value : pairs.second)
     {
       std::cout<<value<<" ";
     }
     std::cout<<"\n";
  }  
  getStronglyConnectedComponents(g);
  return 0;
}
