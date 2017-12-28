#include <iostream>
#include <vector>

using namespace std;

//Selecting subsets is same is combinations of a set wherein we have to select one or more numbers and the order matters.
// In the recursion loop we start out 1 to n and for every num we add it and recursively call the function again.
// every number has 2 choices either its a part of the list or its not part of the tempresult.
// Both choices are made and the resultant recursion is called back
void getAllCombinationsHelper(vector<vector<int>>& res,int start,vector<int> nums,vector<int> tempResult)
{
   res.push_back(tempResult);
   for(int i=start;i<nums.size();++i)
   {
      tempResult.push_back(nums[i]);
      getAllCombinationsHelper(res,i+1,nums,tempResult);
      tempResult.pop_back();
   }
}

vector<vector<int>> getAllCombinations(vector<int> nums)
{
  vector<vector<int>> result;
  getAllCombinationsHelper(result,0,nums,vector<int>());
  return result;
}

int main()
{  
   vector<int> nums;
   int n;
   cout<<"\n Enter the number of inputs";
   cin>>n;
   cout<<"\n Enter the inputs";
   for(int i=0;i<n;i++)
   {
      int num;
      cin>>num;
      nums.push_back(num);
   }
   for(auto&& vec : getAllCombinations(nums))
   {
      cout<<"\n";
      for(auto&& num : vec)
        cout<<num<<"--->";
   }
   return 0;
}
