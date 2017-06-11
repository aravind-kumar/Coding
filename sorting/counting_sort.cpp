#include <iostream>
#include <algorithm>
#include <vector>

//Bugs
//1.Why is the first elemenet of the sorted array 0
//2.How to handle negative numbers
//3.How to handle with auxillary array

void PrintArray(const std::vector<int>& inputArray) 
{
     for(auto&& i : inputArray)
     {
         std::cout<<i<<"\n";
     }
}

void GetInput(std::vector<int>& inputArray)
{
   std::cout<<"Enter the number of inputs \n";
   std::cin>>num;

   std::cout<<"Enter the inputs \n";
   for (int i=0;i<num;++i)
   {
      int input;
      std::cin>>input;
      inputArray.push_back(input);
   }

}

void CountSort(std::vector<int>& inputArray)
{
   unsigned long int maxElement = *std::max_element(inputArray.begin(),inputArray.end());
   std::vector<int> countArray(maxElement+1,0);
   std::vector<int> sumArray;
   std::vector<int> sortedArray(inputArray.size()+1);

   for(auto&& i : inputArray)
   {
      ++countArray[i];
   }
   std::cout<<"The Count Array is \n";
   
   PrintArray(countArray);

   sumArray=countArray;
   for(int i=1;i<sumArray.size();++i)
   {
       sumArray[i]+=sumArray[i-1];
   }
   std::cout<<"The Sum Array is \n";
   
   PrintArray(sumArray);
   
   std::vector<int>::reverse_iterator it=inputArray.rbegin();
   
   for(;it!=inputArray.rend();++it)
   {
      int indexInSortedArray=sumArray[*it];
      sortedArray[indexInSortedArray] = *it;
      --sumArray[*it];
   } 
   
   inputArray = sortedArray;
   
}

int main()
{
   unsigned long int num;
   std::vector<int> inputArray;
   std::cout<<"Input Array before Sorting\n";
   PrintArray(inputArray);
   CountSort(inputArray);
   std::cout<<"Input Array after Sorting\n";
   PrintArray(inputArray);
   
   return 0;
}

