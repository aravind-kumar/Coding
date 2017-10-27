#include <iostream>
#include <vector>
#include <unordered_map>
#include <assert.h>
#include <algorithm>
#include <utility>


std::vector<int> findTripleSum(std::vector<int> input,int sum)
{
    typedef std::unordered_map<int,uint64_t> countMap;
    countMap inputMap;
    std::vector<int> result;

    for(auto && num : input)
    {
       if(inputMap.find(num) != inputMap.end())
           ++inputMap[num];	 
       else
           inputMap.emplace(num,1);
     }
     
    for(int i=0;i<input.size()-1;++i) 
    {
        int desiredSum = sum-input[i];
        for(int j=i+1;j<input.size();++j)
        {
   	   int numToFind = desiredSum - input[j];
           if(inputMap.find(numToFind) != inputMap.end()
              &&
              inputMap[numToFind])
           {
              --inputMap[numToFind];
                result.push_back(input[i]);
                result.push_back(input[j]);
                result.push_back(numToFind);
           }
        } 
    }
    return result;

}

int main()
{
   int num;
   int sum;
   std::vector<int> inputArray;

   std::cout<<"\n Enter the number of elements";
   std::cin>>num;
   std::cout<<"\n Enter the elements";
   
   for(int i=0;i<num;++i)
   {
      int input;
      std::cin>>input;
      inputArray.push_back(input);
   }
   
   std::cout<<"\n Enter the desired sum";
   std::cin>>sum;
 
   int count=0;
   for(auto && elem : findTripleSum(inputArray,sum))
   { 
     
      std::cout<<elem<<",";
   }
   return 0;
}

