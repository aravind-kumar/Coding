#include <iostream>
#include <vector>

class Solution {
public:
    bool isValid(int m,int n,int i,int j){
        return i>=0 && j>=0 && i<m && j<n;    
    }
    
    int getNumOfLifes(vector<vector<int>>& board,int i,int j) {
        int m = board.size();
        int n = board[0].size();
        vector<pair<int,int>> coord = {{1,0},{0,1},{-1,0},{0,-1},{1,1},{-1,-1},{1,-1},{-1,1}};
        int count=0;

        for(auto&& move : coord) {
            int newRow = i+move.first;
            int newCol = j+move.second;
            if(isValid(m,n,newRow,newCol)) 
                count+=board[newRow][newCol] & 1;        
            }
        return count;  
    }
    
    void gameOfLife(vector<vector<int>>& board) {
        if(!board.empty()) {
            int m = board.size();
            int n = board[0].size();
            
            for(int i=0;i<m;++i) {
                for(int j=0;j<n;++j) {
                    int numOfLives = getNumOfLifes(board,i,j);
                        
                    if(board[i][j]==1 && (numOfLives==2 || numOfLives==3))
                        board[i][j] = 3;
                    if(board[i][j]==0 && numOfLives==3) 
                        board[i][j] = 2;
                        
                }
            }
            
            for(int i=0;i<m;++i) {
                for(int j=0;j<n;++j) {
                    board[i][j]>>=1;
                }
            }
        }
    }
    
};


int main() 
{


   return 0;
}
