#include <iostream>
#include <algorithm>
#include <vector>

//Bugs
//2.How to handle negative numbers

void PrintArray(const std::vector<int>& inputArray) 
{
     for(auto&& i : inputArray)
     {
         std::cout<<i<<"\n";
     }
}

void GetInput(std::vector<int>& inputArray)
{
   unsigned long int num;
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

void GenerateCountArray(std::vector<int>& inputArray,
                        std::vector<int>& countArray)
{
   for(auto&& i : inputArray)
   {
      ++countArray[i];
   }
}

void GenerateSumArray(std::vector<int>& sumArray)
{
   for(int i=1;i<sumArray.size();++i)
   {
       sumArray[i]+=sumArray[i-1];
   }
}

void SortArray(std::vector<int>& inputArray,
               std::vector<int>& sumArray,
	       std::vector<int>& sortedArray)
{
   std::vector<int>::reverse_iterator it=inputArray.rbegin();
   
   for(;it!=inputArray.rend();++it)
   {
      int indexInSortedArray=sumArray[*it];
      sortedArray[indexInSortedArray-1] = *it;
      --sumArray[*it];
   } 
 
   inputArray = sortedArray;
}

void CountSort(std::vector<int>& inputArray)
{
   unsigned long int maxElement = *std::max_element(inputArray.begin(),inputArray.end());
   std::vector<int> countArray(maxElement+1,0);
   std::vector<int> sortedArray(inputArray.size());

   GenerateCountArray(inputArray,countArray); 

   GenerateSumArray(countArray);
   
   SortArray(inputArray,countArray,sortedArray);  
   
}

int main()
{
   std::vector<int> inputArray;
   GetInput(inputArray);
   std::cout<<"Input Array before Sorting\n";

   PrintArray(inputArray);
   CountSort(inputArray);

   std::cout<<"Input Array after Sorting\n";
   PrintArray(inputArray);
   
   return 0;
}

