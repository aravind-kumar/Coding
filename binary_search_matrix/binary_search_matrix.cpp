#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(matrix.empty() || matrix.front().empty()) return false;
        
        int start = 0,end = matrix.size()-1;
        int rowNum = -1;
        while(start<=end) {
            int mid = start + (end-start)/2;
            vector<int> row = matrix[mid];
            if(target>=row.front() && target <=row.back()) {
                rowNum = mid;
                break;
            } else if(target>row.front() && target>row.back()) {
                start = mid+1;
            } else if(target<row.front() && target<row.back()) {
                end = mid-1;
            }
        }
        if(rowNum!=-1) {
            vector<int> row = matrix[rowNum];
            int start = 0,end = row.size()-1;
            while(start<=end) {
                int mid = start + (end-start)/2;
                
                if(target == row[mid])
                    return true;
                else if(target > row[mid]) {
                    start = mid+1;    
                }       
                else {
                    end = mid-1; 
                }      
            }
        }
        return false;
        
    }
};


int main() {



    return 0;
}
