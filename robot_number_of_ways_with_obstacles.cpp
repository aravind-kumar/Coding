#include <iostream>
#include <vector>

using namespace std;


// This is same as unique number of paths but we have obstacles in this given problem.
// Obstacles are repersented as 1 in the matrix
// Hence we use the same logic as the previous problem (robot number of ways) but also make sure that the
// point under consideration isnt 1.

// Futher points of optmization are : We could reduce the space from a matix to a vector and one variable
// We could also reuse the same space as that of computing as well.
// But if we use that approach then we have to go top-down approach rather than bottom up approach.

int uniquePathsHelper(int m,int n,vector<vector<int>>& cache,vector<vector<int>> obstacleGrid) {
        
        if(m>=0 && n>=0 && obstacleGrid[m][n] != 1) {
            if(m==0 && n==0) return 1;
            
            if(cache[m][n] != -1) return cache[m][n];
            
            int ans = uniquePathsHelper(m-1,n,cache,obstacleGrid) + uniquePathsHelper(m,n-1,cache,obstacleGrid);
            cache[m][n] = ans;
            return ans;
            
        }
        return 0;
    }
    
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        
        if(obstacleGrid.empty()) return 0;
        
        int m = obstacleGrid.size(),n=obstacleGrid[0].size();
        
        vector<vector<int>> cache(m,vector<int>(n,-1));
        
        return uniquePathsHelper(m-1,n-1,cache,obstacleGrid);
        
    }

int main() {

  int m;
  int n;
  cout<<"\n Enter the number of rows and columns";
  cin>>m>>n;
  
  vector<vector<int>> matrix(m,vector<int>(n));
  
  cout<<"\n Enter the input matrix";
  for(int i=0;i<m;++i) {
     int input;
     for(int j=0;j<n;++j) {
     cin>>input;
     matrix[i][j] = input;
     }
  }
  cout<<"\n The number of unique ways is " <<uniquePathsWithObstacles(matrix);
  return 0;
}
