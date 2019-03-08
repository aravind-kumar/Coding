class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> result;
        vector<int> intermediate;
        generate(1,numRows,{1},result);
        return result;   
    }
    
    void generate(int current,int numRows,vector<int> pre,vector<vector<int>>& result) {
        if(current <= numRows) {
            vector<int> intermediate(current,1);
            
            for(int i=1,j=0,k=j+1;i<intermediate.size()-1;++i,++j,k=j+1) {
                intermediate[i] = pre[j]+pre[k];
            }
            result.push_back(intermediate);
            generate(current+1,numRows,intermediate,result);
        }
    }
};

//Every row of the pascal triangle depends upon the previous rows.
// The number of elements on each row depends upon the row number.
// The elements on the current row are determined from the elements from the previous row.
// Watch the leetcode animation to get a better picture of whats going on.
