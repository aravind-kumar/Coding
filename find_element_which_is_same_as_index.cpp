#include <iostream>
#include <vector>

template <typename T>
int find_element_equals_index(const std::vector<T>& inputVector)
{
   int low=0,high = inputVector.size()-1;
   while(low<=high)
   {
      int mid = low + ((high - low)>>2);
      if(mid == inputVector[mid])
	  return mid;
      else if(inputVector[mid] < mid)
          low = mid+1;
      else
          high = mid-1;
   }
   return -1; 
}

int main()
{
   int num;
   std::vector<int> inputArray;
   std::cout<<"\n Enter the number of elements";
   std::cin>>num;
   std::cout<<"\n Enter the elements";
   for(int i=0;i<num;++i)
   {
      int num;
      std::cin>>num;
      inputArray.push_back(num);
   }
   std::cout<<"\n The element with the index is "<<find_element_equals_index(inputArray);
   return 0;
}
