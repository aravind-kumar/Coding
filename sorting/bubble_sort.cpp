#include <iostream>
#include <vector>
#include <algorithm>

void PrintVector(std::vector<int>& inputVector)
{
     for(auto const& i : inputVector)
     {
         std::cout<<i<<"\n";
     }

}

void bubbleSort(std::vector<int>& inputVector)
{
     for(int i=0;i<inputVector.size();++i)
     {
         for(int j=0;j<inputVector.size()-i-1;++j)
         {
             if(inputVector[j+1]<inputVector[j])
	     {
                std::swap(inputVector[j+1],inputVector[j]); 
             }
         }
     }
}

int main()
{
   unsigned int numberOfElements;

   std::cout<<"Enter the number of elements\n";
   std::cin>>numberOfElements;

   std::vector<int> inputArray;
   std::cout<<"Enter the inputs\n";
   for(int i=0;i<numberOfElements;++i)
   {
       int input;
       std::cin>>input;
       inputArray.push_back(input);
   }
   std::cout<<"The input Array is \n";
   PrintVector(inputArray);

   bubbleSort(inputArray);

   std::cout<<"The sorted Array is \n";
   PrintVector(inputArray);
   return 0;
}
	

	


