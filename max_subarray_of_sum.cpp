#include <iostream>
#include <unordered_map>
#include <vector>

typedef std::pair<unsigned int,unsigned int> indices;

void getInput(std::vector<int>& input)
{
    int num;
    std::cout<<"\n Enter the number of elements";
    std::cin>>num;
    std::cout<<"\n Enter the elements";
    for(int i=0;i<num;++i)
    {
        int inputNum;
        std::cin>>inputNum;
        input.push_back(inputNum); 
    }
}

indices findMaxSum(const std::vector<int>& input,const int desiredSum)
{
    typedef std::unordered_map<int,int> sumIndexMap;
    sumIndexMap map;
    int sum = 0;
    for(int i=0;i<input.size();++i)
    {
       sum += input.at(i);
       if(sum == desiredSum)
       {
          return std::pair<int,int>(0,i);
       }
       if(map.find(sum-desiredSum) != map.end())
       {
          return std::pair<int,int>(map[sum-desiredSum],i);
       }
       map[sum] = i;
    }
    return std::pair<int,int>(-1,-1);
}

int main()
{
    int num;
    std::vector<int> input;
    getInput(input);
    std::cout<<"\n Enter the sum";
    std::cin>>num;
    indices range = findMaxSum(input,num);
    std::cout<<"\n The start range is "<<range.first;
    std::cout<<"\n The end range is "<<range.second;
    
    return 0;
   
}
