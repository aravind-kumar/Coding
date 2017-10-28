#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <functional>


//For this problem we are given a roated array and we have to find a specific element in 
// the array.
// We first find the pivot.
// Upon finding the pivot we know that array is subdivided into 2 halfs both of which are
// sorted.
// We use binary search on both the array to find the element.
// Before we do a binary search we check if key lies in the range of the low and high
// of the subarray and only so do we perform a binary search.
template <typename T>
int find_pivot_element(const std::vector<T>& input)
{
   int low = 0,high = input.size()-1;
   while(low <= high)
   {  
      int mid = (low + ((high-low) >>2));
      if(input[mid] > input[mid+1]) return mid+1;
      else if(input[mid] > input[high])
         low = mid+1;
      else
         high = mid-1;
   }
   return -1;
}
 
template <typename T>
int find_search_element(const std::vector<T>& input,const T& key)
{
   int pivot = find_pivot_element(input);
   if(pivot)
   {
      int high1 = input[pivot];
      int low1 = input[0];
      if(key>low1 && key < high1)
      {
         auto res = std::lower_bound(input.begin(),input.begin() + pivot,key,std::greater<T>()); 
         return res-input.begin();
      }
      else 
      {
         auto res=std::lower_bound(input.begin()+pivot,input.end(),key,std::less<T>());
         return res-input.begin();
      }
   }
   return pivot;
   
}

int main()
{
   int num;
   std::vector<int> inputVector;
   std::cout<<"\n Enter the number of elements";
   std::cin>>num;
   for(int i=0;i<num;++i)
   {
      int input;
      std::cin>>input;
      inputVector.push_back(input);
   }
   std::cout<<"\n Enter the element to be searched ";
   std::cin>>num;
   std::cout<<"\n The index of the element is "<<find_search_element(inputVector,num); 
   return 0;
}
