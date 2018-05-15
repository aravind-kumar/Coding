#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int peri = 0;
        
        for(int i=0;i<grid.size();++i) {
            for(int j=0;j<grid[0].size();++j) {
                if(grid[i][j]==1) {
                    int sum = 0;
                    islandPeri(grid,i,j,grid.size(),grid[0].size(),sum);
                    peri+=sum;
                    break;
                }
            }
        }
        return peri;
    }
    
    void islandPeri(vector<vector<int>>& grid, int i,int j,int m,int n,int& sum) {
        if(i>=0 && j>=0 && i<m && j<n && grid[i][j]==1) {
            grid[i][j] = -1;
            
            sum+= i+1 >= m || !grid[i+1][j];
            sum+= j+1 >= n || !grid[i][j+1];
            sum+= i-1 < 0 || !grid[i-1][j];
            sum+= j-1 < 0 || !grid[i][j-1];
            
                     
            islandPeri(grid,i+1,j,m,n,sum);
            islandPeri(grid,i,j+1,m,n,sum);
            islandPeri(grid,i-1,j,m,n,sum);
            islandPeri(grid,i,j-1,m,n,sum);
        }
        
    }
};


int main() {



    return 0;
}
