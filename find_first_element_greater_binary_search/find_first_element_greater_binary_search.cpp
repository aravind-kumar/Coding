#include <iostream>
#include <vector>

//How does this work ??
// We maintain a running element to find the element greater than the key.
// We travese the complete array using binary search 
// Notice we arent returning element using the condition like other 
// binary seaches
// When we find that a element is greater than the key
// we store that location
// and when we look at the left.
// When iterating through the left side we move right everytime the mid is less
// than key.
// Notice that the termination codition is only when low<=high 
// Eventually we would hit that case and we would would have found the element.
template<typename T>
int findFirstElementGreater_Method2(const std::vector<T>& input,const T & key)
{
   int low = 0, high = input.size()-1 ,firstMax = -1;
   while(low<=high)
   {
      int mid = low + ((high-low) >> 2);
      if(input[mid]> key)
         firstMax=mid, high=mid-1;
      else 
         low = mid+1;
   }
   return firstMax;
}

//Linear approach
// Notice that in this approach the time complexity is linear.
// We first do a binary search and find the element such that its left is less
// and its right is greater than the element.
// Upon finding the element we traverse till we find the last position
// This could be linear because if the element happens to be first elemnent 
/// and all but the last position are the same.
// Then we would have a linear time complexity.

template<typename T>
int findFristElementGreater_Method1(const std::vector<T>& input,const T & key)
{
   int low=0,high = input.size()-1;
   int mid=input.size()-1;
   while(low<=high)
   {
      mid = low+((high-low)>>2);
      if(input[mid-1] < key && input[mid+1] >= key)
         return mid;
      else if(input[mid] > key)
         high = mid-1;
      else
         low = mid+1;
   } 
   while(mid < input.size() -1)
   {
      if(input[mid] == input[mid]+1)
       --mid; 
      else 
         return mid;
   }
    
   return -1;
}

int main()
{   
   int num;
   std::vector<int> inputArray;
   std::cout<<"\n Enter the number of element";
   std::cin>>num;
   for(int i=0;i<num;++i)
   {
      int input;
      std::cin>>input;
      inputArray.push_back(input);
   }
   std::cout<<"\n Enter the key to search for";
   std::cin>>num;
   std::cout<<"\n The first index greater than the element is "
	<<findFirstElementGreater_Method2(inputArray,num);
   return 0;
}
