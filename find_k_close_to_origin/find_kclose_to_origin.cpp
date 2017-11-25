#include <iostream>
#include <queue>
#include <vector>

using namespace std;

template <typename T>
vector<T> find_k_closest_to_origin(const vector<T>& input,int k)
{
   priority_queue<T,vector<T>> max_heap;
   for(int i=input.size()-1;i>k;--i)
   {
      max_heap.emplace(k);
      input.pop_back(); 
   }
   vector<T> res;
   while(!input.empty())  
   {
     if(input.back() < max_heap.top())
     {
          max_heap.pop();
          max_heap.emplace(input.back()); 
     }
     else
     	input.pop_back();
   }

}

int main()
{

   return 0;
}
