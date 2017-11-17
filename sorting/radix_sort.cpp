#include <iostream>
#include <algorithm>
#include <vector>

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
unsigned int getLastDigit(const int number,const int base)
{
	return (number/base)%10;
}

void GenerateCountArray(std::vector<int>& inputArray,
                        std::vector<int>& countArray,
			const unsigned int base)
{
   for(auto&& i : inputArray)
   {	
      auto lastDigit = getLastDigit(i,base);
      ++countArray[lastDigit];
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
	       std::vector<int>& sortedArray,
	       const unsigned int base)
{
   std::vector<int>::reverse_iterator it=inputArray.rbegin();
   
   for(;it!=inputArray.rend();++it)
   {
      unsigned int lastDigitOfInput = getLastDigit(*it,base); 
      unsigned int indexInSortedArray=sumArray[lastDigitOfInput];
      sortedArray[indexInSortedArray-1] = *it;
      --sumArray[lastDigitOfInput];
   } 
 
   inputArray = sortedArray;
}

void CountSort(std::vector<int>& inputArray,
	       int base=-1)
{
   unsigned long int maxElement = *std::max_element(inputArray.begin(),inputArray.end());
   std::vector<int> countArray(maxElement+1,0);
   std::vector<int> sortedArray(inputArray.size());
   base = (base > 0) ? 
	  base 	     : 
	  [maxElement] () -> int
   	  { 
            unsigned int count=0;
            unsigned long int max=maxElement;
            while(max)
	    {
		max/=10;
                ++count;
            }
            return count;
   	  }();

   GenerateCountArray(inputArray,countArray,base); 

   GenerateSumArray(countArray);
   
   SortArray(inputArray,countArray,sortedArray,base);  
   
}

int main()
{
   std::vector<int> inputArray;
   GetInput(inputArray);
   std::cout<<"Input Array before Sorting\n";

   PrintArray(inputArray);
   unsigned long int maxElement = *std::max_element(inputArray.begin(),inputArray.end());
   for(int i=1; (maxElement/i)>0 ; i*=10)
   	CountSort(inputArray,i);

   std::cout<<"Input Array after Sorting\n";
   PrintArray(inputArray);
   
   return 0;
}

