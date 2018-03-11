class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        if (matrix.empty()) return 0;
        int m=matrix.size(),n=matrix[0].size();
        
        vector<vector<int>> memo(m,vector<int>(n,0));
        int maxSize = INT_MIN;
        
        // Intiliaze the first row
        // If we have input as row matrix with any 1 then maxSize = 1
        for(int i=0;i<matrix.front().size();++i) {
            if(matrix[0][i] == '1') {
                memo[0][i] = 1;
                maxSize=1;
            } 
        } 
        
        // Intiliaze the first col
        // If we have input as a col matrix with any 1 then maxSize = 1
        for(int i=0;i<matrix.size();++i) {
            if (matrix[i][0] == '1') {
                memo[i][0] = 1;
                maxSize=1;
            }
        }
        
        
        // Now the memo[i][j] == max size of square matrix 
        // We are choosing min here instead of max because min would be the value thats common amoung all the values 
        // values of left,top and diag
        // If we take the max that may only pertain to a single row but not all remmber that inorder to form a proper square 
        // all the values on left,top,diag must have the common values.
        // Say one of the values is 0 (diag) and the rest are 1 then we cannot form a square hence we form a square of size >1 
        // because the diag can at max have only 0 elements
        // Hence we must fill it a sqaure of size 1 i.e one element.
        
        for(int i=1;i<m;++i) {
            for(int j=1;j<n;++j) {
                
                if(matrix[i][j]=='1') {
                    int left = memo[i-1][j];
                    int top = memo[i][j-1];
                    int diag = memo[i-1][j-1];
                    int minSize = min(left,min(top,diag))+1;
                    memo[i][j] = minSize;
                    maxSize = max(maxSize,minSize);    
                }
                
            }
        }

        return maxSize!=INT_MIN ? maxSize*maxSize : 0;
    }
};


int main() {
   
   Solution s;
   vector<vector<int>> input;
   cout<<"\n The maximum size of square in submatrix is "<<s.maximalSquare(input);


}
