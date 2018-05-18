#include <iostream>
#include <vector>
#include <priority_queue>

using namespace std;



vector<int> sortKMessedArray( const vector<int>& arr, int k ) 
{
  vector<int> ans;
  priority_queue<int, std::vector<int>, std::greater<int>> heap;
  for(int i=0;i<arr.size();++i) {
    if(!(i%k)) {  
         ans.push_back(heap.top());
         heap.pop();
      }
      
    } else {
      heap.push(arr[i]);
      if(heap.size()==k+1) {
         ans.push_back(heap.top());
         heap.pop();
      }
    }
  }
  
  
  return ans; 
  // your code goes here
}

int main() {
  return 0;
}


