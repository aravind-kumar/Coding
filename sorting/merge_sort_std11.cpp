#include <iostream>
#include <vector>
#include <algorithm>

void PrintArray(std::vector<int>& inputVector)
{
   for(auto&& element:inputVector)
   {
       std::cout<<element<<"\n";
   }

}

void SortArray(std::vector<int>& inputVector)
{
    MergeSortHelper(inputVector.begin(),inputVector.end());
}

int main()
{
   std::vector<int> inputArray;
   unsigned long int num;

   std::cout<<"Enter the number of inputs \n";
   std::cin>>num;

   std::cout<<"Enter the inputs \n";
   for(int i=0;i<num;++i)
   {
       unsigned long int input;
       std::cin>>input;
       inputArray.push_back(input);
   }
   
   std::cout<<"Array before sorting \n";
   PrintArray(inputArray);   
   SortArray(inputArray);
   std::cout<<"Array after sorting \n";
   PrintArray(inputArray);

}
