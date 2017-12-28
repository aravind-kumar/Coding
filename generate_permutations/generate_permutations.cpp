#include <iostream>
#include <vector>

using namespace std;

void generatePermutationsHelper(vector<vector<int>>& res,vector<int> nums,vector<int> intermediateResult)
{
   if(intermediateResult.size() == nums.size())
   {
      cout<<"\n Adding the result\n";
      for(auto&& vec : intermediateResult)
         cout<<vec<<"--->";
      res.push_back(intermediateResult);
   }

   for(int i=0;i<nums.size();++i)
   {
     cout<<"I:"<<i<<"\n";
     if(find(intermediateResult.begin(),intermediateResult.end(),nums[i]) != intermediateResult.end())
     {
         cout<<"Skipping for the I";
         continue; 
     }
     cout<<"\n Adding into intermediate" <<nums[i];
     intermediateResult.push_back(nums[i]);
     cout<<"\n Calling recusively with added";
     generatePermutationsHelper(res,nums,intermediateResult);
     intermediateResult.pop_back();
     cout<<"\n Removing the result";
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
