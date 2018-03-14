#include <iostream>
#include <vector>

using namespace std;
    
  
 // Given a grid we have to find the path whose sum of distance is the minimum amoung rest
 // We are only allowed to move in i-1,j and i,j-1 directions
 // We have to find a path that minimizes the total distance
 // We use DP to solve this problem the minimum distance required to reach i,j equals
 // min of i-1,j and i,j-1 + the distance to reach the current cell which is grid[i][j]
 // This can further be optimized by only using a variable and a vector instead of using a complete cache 2d vector.
 
int minPathHelper(int i,int j,vector<vector<int>>& cache,vector<vector<int>> grid) {
        
        
        if(i>=0 && j>=0) {
            
            if(i==0 && j==0) return grid[0][0];
            
            if(cache[i][j] != -1) return cache[i][j];
            
            int ans = min(minPathHelper(i-1,j,cache,grid),
                          minPathHelper(i,j-1,cache,grid)) + grid[i][j];
         
            cache[i][j] = ans;
            return ans;
            
        }
        return INT_MAX;
}

int minPathSum(vector<vector<int>>& grid) {
        
        if(grid.empty()) return 0;
        
        int m=grid.size();
        int n=grid.front().size();
        
        vector<vector<int>> cache(m,vector<int>(n,-1));
        
        int ans = minPathHelper(m-1,n-1,cache,grid);
        return  ans == INT_MAX ? 0 : ans;
        
}


int main() {
   
   int m,n;
   vector<vector<int>> matrix;
   
   cin>>m>>n;
   
   for(int i=0;i<m;++i) {
      for(int j=0;j<n;++j) {
        int input;
        cin>>input;
        matrix[i][j] = input;
      }
   }
  
   cout<<"\n Minimum path sum is "<<minPathSum(matrix);
   return 0;
}
