#include <iostream>
#include <queue>
#include <vector>

using namespace std;

template<typname T>
vector<T> merge_k_sorted_list(const vector<vector<T>>& input)
{
    typedef pair<T,int> elementSourceIndex
    priority_queue<elementSourceIndex,vector<elementSourceIndex>> min_heap;
    vector<int> currentElementIndex(input.size(),0);

    for(int i=0;i<input.size();++i)
    {
       if(input[i].size())
       {
          min_heap.emplace(input[i].front(),i));
          currentElementIndex[i]=1;
       } 
    }
    
    vector<int> result; 
    while(!min_heap.empty())
    {
      auto topElem = min_heap.top();
      result.emplace(topElem.first());
      if(currentElementIndex[topElem.second] < input[topElem.second].size())
      {
          ++currentElementIndex[topEleme.second];
          auto nextElem = input[topElem.second][currentElementIndex[topElem.second]];
          min_heap.emplace(nextElem,topElem.second);
      }
      result.pop();
         

    }

}
int main()
{
   priority_queue<pair<int,int>,vector<pair<int,int>
   return 0;
}
