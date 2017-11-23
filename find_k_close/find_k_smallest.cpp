#include <iostream>
#include <queue>
#include <vector>

using namespace std;


// Here we are creating a heap of size n.
// We are given a list of k sorted elements.
// where k is the number of elements but each sub-array can inturn have many elements
// now we can create a max-heap of size sum_of_each subarray.
// But we only need a heap of size n.
// We insert the first n elements into the heap and pick the max and insert into the result list.
// We now would have a problem since each subarray can be of varying sizes how do we know know the 
// current sub-array size and more importantly how do we know where the max/min element picked belongs to in the input array.
// 1.Problem : How do we find the subarray and the corresponding position from where the top element came ?
// 2.Problem : If we found the element how do we know how many more elements are to be iteratreated into ?
// Solution : We maintain a map with key represeting the subarray index's and its value representing the current elements position which is p// present in the heap.
// We insert the pair into the heap , wherein the pair's first corresponds to the element and second corresponds to the key of the map.
//
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
