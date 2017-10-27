#include <iostream>
#include <vector>

template <typename T>
int find_first_occurence(const std::vector<T>& input,const T & k)
{
   int low = 0;
   int high = input.size();
   while(low< high)
   {
      int mid = low + (high-low)/2;
      if(input[mid] ==k && input[mid-1] != k)
 	return mid;
      else if(input[mid] < k)
        low = mid+1;
      else if(input[mid]>=k)
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
      int givenInput;
      std::cin>>givenInput;
      inputArray.push_back(givenInput);
   }
   std::cout<<"\n Enter the number to be found";
   std::cin>>num;
   std::cout<<"\n The first occurence is "<<find_first_occurence(inputArray,num);
   return 0;
}
