#include <iostream>
#include <vector>

// This is similar to matrix I search.
// but in this we have both the rows and columns sorted.
// we start from the bottom left and move to next column or upper rows.
// depending upon the target value.
// Reffer to the solution section of the question, it has a video.
bool searchMatrix(vector<vector<int>>& matrix, int target) {
    if(!matrix.empty() && !matrix.front().empty()) {
        int col=0,row=matrix.size()-1;
        while(row>=0 && row<=matrix.size()-1 && col>=0 && col<=matrix.front().size()-1) {
            if(matrix[row][col]>target) {
                --row;
            } else if(matrix[row][col]<target) {
                ++col;
            } else {
                return true;
            }
        }
        
    }
    return false;
    
}

int main() {



    return 0;
}
