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

void Merge(std::vector<int>& inputVector,
	   unsigned int low,
	   unsigned int mid,
	   unsigned int high)
{
   std::vector<int> lowerHalf(inputVector.begin()+low,inputVector.begin()+mid+1);
   std::vector<int> upperHalf(inputVector.begin()+mid+1,inputVector.begin()+high+1);
   
   unsigned int sortedIndex = low; 
   unsigned int lowerIndex = 0;
   unsigned int upperIndex = 0;
   
   while(lowerIndex < lowerHalf.size()
         &&
         upperIndex < upperHalf.size())
   {
         if(lowerHalf[lowerIndex] <= upperHalf[upperIndex])
         {
            inputVector[sortedIndex] = lowerHalf[lowerIndex];
            ++lowerIndex;
         } 
         else
         {
             inputVector[sortedIndex] = upperHalf[upperIndex];
             ++upperIndex;
         }
         ++sortedIndex;
   }
   
   while(lowerIndex < lowerHalf.size())
   {
      inputVector[sortedIndex] = lowerHalf[lowerIndex];
      ++lowerIndex;
      ++sortedIndex;
   } 
   
   while(upperIndex < upperHalf.size())
   {
      inputVector[sortedIndex] = upperHalf[upperIndex];
      ++upperIndex;
      ++sortedIndex;
   }
}

void MergeSortHelper(std::vector<int>& inputVector,unsigned int low,unsigned int high)
{
     if(low<high)
     {
           unsigned int mid = low+(high - low)/2;
           MergeSortHelper(inputVector,low,mid);
           MergeSortHelper(inputVector,mid+1,high);
           Merge(inputVector,low,mid,high);
     }
}

void SortArray(std::vector<int>& inputVector)
{
    MergeSortHelper(inputVector,0,inputVector.size()-1);
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
