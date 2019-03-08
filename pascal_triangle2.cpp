class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> temp(rowIndex+1,0);
        temp[0] = 1;
        for(int i=1;i<temp.size();++i){
            for(int j=i;j>=1;--j) {
                temp[j]+=temp[j-1];
            }
        }
            
        return temp;
        
    }
};
