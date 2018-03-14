#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;


// Given a robot which starts at 0,0 and the destination is m,n find the number of unique ways by 
// which the robot can reach the destination given that we can only move down or right
// We use dynamic programming to solve this problem 
// Because we have overlapping subproblems 
// The number of ways to reach a cell depends upon the number of ways to reach i-1 and j-1;
// Where i and j are rows and columsns of a cell.
// The number of ways to reach i,j depends upon i-1,j and i,j-1 which again depends upon i-2,j-1 and i-1,j-2
// This would repeat for each cell and thus we cache the results.


// We can further optimize the solution because at given point int time the solution depends upon i-1 and i,j-1 
// We could just use a variable and a vector to solve the above problem.

int uniquePathsHelper(int i,int j,vector<vector<int>>& cache) {
        if(i>=0 && j>=0) {
            
            if(i==0 && j==0) return 1;
            
            if(cache[i][j] != -1) return cache[i][j];
        
            int ans = uniquePathsHelper(i-1,j,cache) + uniquePathsHelper(i,j-1,cache);
            cache[i][j] = ans;
            return ans;    
        }
        return 0;
    }
    
    int uniquePaths(int m, int n) {
        
        if(m!=0 || n!=0) {  
            vector<vector<int>> cache(m,vector<int>(n,-1));
            return uniquePathsHelper(m-1,n-1,cache);     
        }       
    }
    
    
int main() {

  int n;
  int m;
  cin>>m>>n;
  
  cout<<"\n The number of ways to reach destination is "<<uniquePaths(m,n);

  return 0;
}
