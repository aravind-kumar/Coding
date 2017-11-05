#include <iostream>
#include <unordered_map>
#include <vector>

using std::cout;
using std::cin;
using std::vector;
using std::unordered_map;


int countSubArraySum(const vector<int>& input,const int& desiredSum)
{
    typedef unordered_map<int,int> sumCountMap;
    sumCountMap inputMap;
    int count=0;
    int sum=0;
    inputMap[0]=1;
    for(auto number : input)
    {
       sum+=number;
       if(inputMap.find(sum-desiredSum) != inputMap.end())
       {
          count+=inputMap.at(sum-desiredSum); 
       }
       if(inputMap.find(sum) != inputMap.end())
          inputMap[sum] = count +1;
       else
	  inputMap[sum] = 1; 
    }
    return count;
}

void getInput(vector<int>& input)
{
   int num;
   cout<<"\n Enter the number of inputs";
   cin>>num;
   cout<<"\n Enter the inputs";
   for(int i=0;i<num;++i)
   {
      int inputNum;
      cin>>inputNum;
      input.push_back(inputNum); 
   }
}

int main()
{
   int sum;
   vector<int> input;
   getInput(input);
   cout<<"\n Enter the required sum";
   cin>>sum;
   cout<<"\n The number of subarrays with count is "<<countSubArraySum(input,sum);
   return 0;
}
