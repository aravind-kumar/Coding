#include <iostream>
#include <vector>

vector<vector<int>> generateMatrix(int n) {
    vector<vector<int>> matrix(n,vector<int>(n));
    if(n){
        int num = 1;
        int rowLow = 0;
        int rowMax = matrix.size()-1;
        int colLow = 0;
        int colMax = matrix.front().size()-1;
        
        while(rowLow<=rowMax && colLow<=colMax) {
            for(int i=colLow;i<=colMax;++i) {
                matrix[rowLow][i]=num;
                ++num;
            }
            for(int i=rowLow+1;i<=rowMax;++i) {
                matrix[i][colMax]=num;
                ++num;
            }
            if(rowLow<rowMax && colLow<colMax) {
                for(int i=colMax-1;i>colLow;--i) {
                    matrix[rowMax][i]=num;
                    ++num;
                }
                for(int i=colMax;i>colLow;--i) {
                    matrix[i][colLow]=num;
                    ++num;
                }
            }
            ++rowLow;
            --rowMax;
            ++colLow;
            --colMax;
        }
    }
    return matrix;
}

int main() {


    return 0;
}
