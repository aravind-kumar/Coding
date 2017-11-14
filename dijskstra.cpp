#include <iostream>
#include <unordered_map>
#include <vector>
#include <queue>
#include <algorithms>

using std::cout;
using std::cin;
using std::vector;
using std::queue;

typedef unordered_map<int,vector<int>> graph;

unordered_map<int,int> getALlShortestPaths(const graph& input,int src)
{
    unordered_map<int,int> minHeap(input.size());

    if(input.find(src) != input.end())
    {
       intiliaze(g,result,src);
       unordered_map<int,int> finiliazedVetices = {pair(src,0)};
       while(minHeap.size())
       {
            auto min = minHeap.front();
            pop_heap(minHeap.begin(),minHeap.end());
            minHeap.pop_back();
            for(auto&& destinations : input[min.first])
            {
               if(minHeap[destination] > result[min.first] + min.second)
               {
                   result[destination] = result[min.first] + min.second;
            }
       }
       return finiliazedVertices;
    } 
    return result; 
}

void getInput(graph& input)
{


}

int main()
{
  int num;
  graph g;
  getInput(g);
  cout<<"\n Enter the source vertex";
  cin>>num;
  vector<int> result = getAllShortestPaths(g,num); 
  return 0;
}
