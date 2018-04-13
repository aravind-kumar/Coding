#include <iostream>
#include <vector>

using namespace std;

    int maxAreaOfIsland(vector<vector<int>>& grid) {   
        int rows=grid.size();
        if(rows==0) return 0;
        int cols=grid[0].size();
        int maxNum = 0;
        for(int i=0;i<rows;++i)
        {
            for(int j=0;j<cols;++j)
            {
                if(grid[i][j])
                {
                    maxNum = max(maxNum,getArea(grid,i,j,0));
                }
            }
        }
        return maxNum;
    }
    
    int getArea(vector<vector<int>>& grid,int i,int j,int sum)
    {
        if(i>=0 && i<grid.size() && j>=0 && j<grid[0].size() && grid[i][j])
        {
            grid[i][j]=0;
            int lsum = getArea(grid,i,j-1,sum);
            int rsum = getArea(grid,i,j+1,sum);
            int tsum = getArea(grid,i-1,j,sum);
            int bsum = getArea(grid,i+1,j,sum);
            return sum+lsum+rsum+tsum+bsum+1;
        }
        return 0;
    }
};

int main() {



   return 0;
}
