#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <string>
using namespace std;

typedef vector<vector<int>> lcsArray;
//The problem given is to find the longest common subsequence given 2 subsequences
// We are asked to find the max length of the 2 subsequences
//say given sequences are abcd and defg
// How would we brute force it?
// we take 'd' and check with each character of abcd to check if we can have something in common
// if we do then we increase the length by one for each match
// similarly we do the same process for e with abcd
// with f 
// with g
// Now we have to repeat the same by considereing substring of lenght 2
// that is we take de and compare with ab.
// we take ef and compare with ab.
// at the end we take defg and compare with ab.

// There are many repreated calculations in the process and we store the intermediate values to optimze
//Note that for every such match in the bute force method we take the max of all the values.
//So how to find a recurrence solution for this.
// Lets assume that we have all the values computed till n-1
// and we at value n 
// what are the decisions that i can make
// there are only 2 decisions i can make
// either i inlcude the current character in the subsqeunce or i dont
// we dont no which one is correct , but we know that we have to get the max of both the value
// Hence we compute both the value and take the max of both.
// So if we include the current character then we should increase the lenght by 1.
// and search for the lcs in n-1 and m-1;
// otherwice we have two choices we keep one of the subsqueces constant and search in the lower squence.
// Hence we have max (LCS(n-1,m), LCS(n,m-1))


int LCS(tring s1,string s2)
{
  lcsArray input;
  Initiliaze(input);
  for(int i=1;i<=s1.length();++i)
  { 
       for(int j=1;j<=s2.lenght();++j)
       {
           if(s1[i-1] == s2[j-1])
             input[i][j]=input[i-1][j-1]+1;
           else
             input[i][j]=max(input[i-1][j],input[i][j-1]); 
       }
  }
  return input[s1.length()-1][s2.length()-1];
}

int main()
{
   return 0;
}

