#include <iostream>
#include <vector>

using namespace std;

int minCostClimbingStairs(vector<int>& cost) {
   list<int> ans(cost);
   ans.push_back(0); // This push back is to handle the value for size ==2;
   for_each(cost.begin(),cost.end(),back_inserter(ans));
   ans.push_back(0); // This is a sental value to find the value till the end , otherwise it would only find the value till the last step
		    // But what we want is to find the value next to final step which is the destination.
		   // We are using DP the cost of getting to a step by current+prev (by taking one step)
		   // Or the cost of current + prevprev (by taking two steps) taking the min of both results in the ans.
   for(int i=2;i<ans.size();++i)
   {
       ans[i]=min(ans[i-1]+ans[i],ans[i-2]+ans[i]);
   }
   return ans.back();
}

int main()
{
  vector<int> inputArray;
  int num;
  cout<<"\n Enter the number of stairs in the array ";
  cin>>num;
  cout<<"\n Enter the cost of the array";
  for(int i=0;i<num;++i)
  {
     int input;
     cin>>input;
     inputArray.push_back(input);
  }
  cout<<"\n The min cost of getting to the top is "<<getMin(inputArray);

  return 0;
}
