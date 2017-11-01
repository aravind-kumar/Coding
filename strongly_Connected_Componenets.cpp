#include <iostrea>
#include <unordered_map>
#include <vector>
#include <stack>
#include <bitset>
#include <function>

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
typedef bitset<(1<<32)> visitedNodes(0);

void DFS(const graph& inputGraph,
	 const int& node,
         visitedNodes& visited,function<(int num)> f)
{
  auto isNotVisted = [visited](int num) { return (visited[num]==false);}; 
  nodes unvisited;

  auto end =copy_if(inputGraph[node].begin(),inputGraph.end(),
          	        unvisited.begin(), isNotVisited);

  unvisited.resize(std::distance(unvisted.begin(),end));
  for(auto&& destinationNode : unvisited)
  {
     visited[destinationNode]=1;
     DFS(inputGraph,destinationNode,visited);
  }
  f(node);
}

void getFinishTimes(const graph& g,finishTimeStack inputStack)
{
  visitedNodes visted;
  auto addToStack = [&inputStack](int num) { inputStack.push(num);} ;
  for(auto node : g)
  {
      DFS(g,node.first,visited,addToStack);
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
     	DFS(g,inputStack.top(),visited,printConnectedComponents);
     inputStack.pop();    
   }
}

graph getTraspose(graph g)
{
   graph newGraph;
   for(auto key: g)
   {
      for(auto value :element.second) 
      {
           newGraph[value].push_back(key);  
      }
   } 

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
