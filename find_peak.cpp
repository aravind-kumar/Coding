#include <iostream>
#include <vector>
#include <assert.h>

template <typename T>
int findPeakElement(const std::vector<T> & input)
{
   int low=0;
   int high = input.size();
   while(low<high)
   {
      int mid = low+(high-low)/2;
      if(input[mid-1] < input[mid] 
          &&
         input[mid+1] < input[mid])
      {
          return mid;
      }
      else if(input[mid-1]<=input[mid])
       	    low=mid;
      else 
            high=mid;
   }
   return -1;
}

int main()
{
   int num;
   std::vector<int> inputArray;
   std::cout<<"\n Enter the number of inputs";
   std::cin>>num;
   std::cout<<"\n Enter the elements";
   for(int i=0;i<num;++i)
   {
     int input;
     std::cin>>input;
     inputArray.push_back(input);
   }
   std::cout<<"\n The peak element is "<<findPeakElement(inputArray);
   return 0;
}
