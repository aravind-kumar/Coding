#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <assert.h>

using namespace std;


//The ask is to find the longest increasing subsequence
//So what are the inputs the input is a subsequence
//What is the expected output the max lenght.
//Since input is singular we only need an array.
//Each value in a cell represents the max lenght that can be obtained by adding that element.
//Now what are the subproblems:
// The subproblem is that for a given n it uses the max length of 0-n-1 
// Because we have to combine the nth element with the all the elements of n-1 such that it forms an increasing sequence
// Now for all those with which when combined we get a new length , we take the max of all of them and to get the max for the current one.
// That is for a given element n
// we compare with all the elements from 0-n-1 with all those elements with which its increasing find the length of all the ones.
// Once we get all the lenght we take the max of all of them
int LIS(vector<int> input)
{
   vector<int> lis(input.size(),1);
   for(int i=1;i<=input.size();++i)
   {
       if(input[i] > input[i-1])
       {
         int maxTillNow = *(max_element(lis.begin(),lis.begin()+i));
         lis[i]=maxTillNow+1;
       }
   }
   return lis.back(); 
}

int main()
{
  vector<int> input={10, 22, 9, 33, 21, 50, 41, 60};
  cout<<LIS(input);
}
