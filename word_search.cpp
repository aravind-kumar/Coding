#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool isPresent(vector<vector<char>>& board,string word,int index,pair<int,int> boardIndex,int m,int n) {
        
        if(boardIndex.first>=0 && boardIndex.first<m & boardIndex.second>=0 && boardIndex.second<n
           && board[boardIndex.first][boardIndex.second] != ' ' && index < word.size()) {
           
           
            bool ans = false; // This is to short circuit if a result is to be found on left,right,top,bottom 
                              // Then we need not check for the rest
                              
            bool result = board[boardIndex.first][boardIndex.second] == word[index];
    
            
            char temp = board[boardIndex.first][boardIndex.second];
            
            board[boardIndex.first][boardIndex.second] = ' '; //This is to make sure that we dont recursive loop back 
                                                              // and form a cycle.
            
            if(index == word.size()-1 && result) return true;   
            

            ans = ans || (result && isPresent(board,word,index+1,{boardIndex.first,boardIndex.second-1},m,n));

            ans = ans || (result && isPresent(board,word,index+1,{boardIndex.first,boardIndex.second+1},m,n));

            ans = ans || (result && isPresent(board,word,index+1,{boardIndex.first-1,boardIndex.second},m,n));

            ans = ans || (result && isPresent(board,word,index+1,{boardIndex.first+1,boardIndex.second},m,n));

            
            board[boardIndex.first][boardIndex.second] = temp;
            // We have to restore the state back because if don't find it the given starting point i,j doest mean 
            // that if started from other starting points the value wouldn't exsist.
            // Hence we have to restore that when the starting point is changed we can recheck.
            // Otherwise we wouldn't check since it has been set to ' '
            // Our only goal is to make sure that within the same iteration of DFS we dont loopback once we are done
            // with the dfs we should restore.    
            
            return ans;
            
            }
        
        return false;
    }
    
    bool exist(vector<vector<char>>& board, string word) {
        for(int i=0;i<board.size();++i) {
            for(int j=0;j<board.front().size();++j) {
                if(board[i][j] == word[0]) {
                    pair<int,int> index={i,j};
                    if(isPresent(board,word,0,index,board.size(),board.front().size())) 
                        return true;
                }
            }
        }
        
        return false;
        
    }
};


int main() {


   return 0;
}
