#include <iostream>
#include <unordered_set>

//Question : We are given an input string and a set of words 
// We are asked if the given string can be formed from the set of words in the given map.
// Approach 1 could be to start from i=0 and j=i+1 both less than n and find the prefix and suffix
// if they exsist return true
// otherwise return false.
// this is the brute force and would involve alot of recomputations.
// What we do is reverse of the normal n^2 iterations.
// We start from n , n-1,n-2 ,n-3 and for every such n we iteratrate from n to size.
// This way we need not recompute the strings again and again.
// Rather we could resuse the values computed for the prefixes.
// One way to look at it like a DFS where every node has only one leaf.
// DFS goes to the depth of node and then recurses back from the parent.
// The same happens here.
// We maintain a result array which represents if a suffix starting from i exsists.
// We iterate from the back and after appending if we find that the suffix after appending is already we ignore the iteration 
// because we now know that the complete suffix exsitis 
// so we skip the iteration and proceed to the next one.

bool isWordBreakable(unordered_set<string> map,string input)
{
   vector<bool> result(s.size()+1);
   result[s.size()] = 1;
  
   for(int i=s.size()-1; i>=0;--i)
   {
      string subString;
      for(int j=i;j<s.size();++j)
      {
         subString += s[j];
         result[i] = find(wordDict.begin(),wordDict.end(),subString) != wordDict.end();
         if(result[i] && result[j+1])
           break;
      }

   }
   return result[0];
}

int main()
{
   
   return 0;
}
