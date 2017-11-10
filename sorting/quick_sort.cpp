#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>

void PrintArray(std::vector<int>& inputs)
{
    for(auto&& input:inputs)
    {
       std::cout<<input;
    } 
}

unsigned int Partition(std::vector<int>& inputs,
	       const unsigned int low,
               const unsigned int high)
{
    int pivot =  inputs[high];
    
    int i=low-1;

    for(int j=low;j<=high-1;++j)
    {
        if(inputs[j]<=pivot)
	{
           ++i;
           std::swap(inputs[i],inputs[j]);
        }
    }
    std::swap(inputs[i+1],inputs[high]);
    return i+1;
}

void QuickSortRecursive(std::vector<int>& inputs,
 			const unsigned int low,
 			const unsigned int high)
{
    if(low<high)
    {
        unsigned int pivotPosition = Partition(inputs,low,high);
        QuickSortRecursive(inputs,low,pivotPosition-1);
        QuickSortRecursive(inputs,pivotPosition+1,high);
    }
}

int main()
{
  unsigned int numofInputs;
  std::vector<int> inputs;

  std::cout<<"\n Enter the size of the array";
  std::cin>>numofInputs;
   
  std::cout<<"\n Enter the inputs";
   
  for(unsigned int i=0;i<numofInputs;++i)
  {
      int input;
      std::cin>>input;
      inputs.push_back(input);
  }

  std::cout<<"\n Array before sorting";
  PrintArray(inputs);
   
  QuickSortRecursive(inputs,0,numofInputs-1);
  std::cout<<"\n Array after sorting";
  PrintArray(inputs);
  
 return 0;
}


