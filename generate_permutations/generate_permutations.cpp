#include <iostream>
#include <vector>

using namespace std;

void generatePermutationsHelper(vector<vector<int>>& res,vector<int> nums,vector<int> intermediateResult)
{
   if(intermediateResult.size() == nums.size())
      res.push_back(intermediateResult);
   for(int i=0;i<nums.size();++i)
   {
     if(find(intermediateResult.begin(),intermediateResult.end(),nums[i]) != intermediateResult.end())
          continue; 
     intermediateResult.push_back(nums[i]);
     generatePermutationsHelper(res,nums,intermediateResult);
     intermediateResult.pop_back();
   }
}

vector<vector<int>> generatePermutations(vector<int> nums)
{
   vector<vector<int>> result;
   generatePermutationsHelper(result,nums,vector<int>());
   return result;
}

int main()
{
   vector<int> input;
   int n;
   cout<<"\n Enter the number of inputs";
   cin>>n;
   cout<<"\n Enter the inputs";
   for(int i=0;i<n;++i)
   {
     int num;
     cin>>num;
     input.push_back(num);
   }
   cout<<"\n The permutations are ";
   for(auto&& vec : generatePermutations(input))
   {  
     cout<<"\n";
     for(auto&& num:vec)
     {
       cout<<num<<"-->"; 
     }

   }
}
