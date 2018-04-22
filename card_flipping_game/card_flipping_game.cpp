#include <iostream>
#include <vector>

class Solution {
public:
    
    bool isGood(int num,vector<int>& fronts,vector<int>& backs) {
        vector<int> positions;
        for(int i=0;i<fronts.size();++i) {
            if(fronts[i]==num) {
               // cout<<"pushing"<<i<<endl;
                positions.push_back(i);
            }
        }
        
        for(int i=0;i<positions.size();++i) {
            if(backs[positions[i]] == num) {
               return false;
            }    
        }
        return true;    
    }
    
    int flipgame(vector<int>& fronts, vector<int>& backs) {
        int backNum = INT_MAX;
        for(int i=0;i<backs.size();++i){
            if(isGood(backs[i],fronts,backs)) {
                //cout<<"Good"<<backs[i]<<endl;
                backNum = min(backNum,backs[i]);
            }
        }
        int frontNum = INT_MAX;
        for(int i=0;i<fronts.size();++i){
            if(isGood(fronts[i],backs,fronts)) {
               // cout<<"Good"<<fronts[i]<<endl;
                frontNum = min(frontNum,fronts[i]);
            }
        }
        return backNum!=INT_MAX || frontNum!=INT_MAX ? min(frontNum,backNum): 0;
    }
};


int main() {



    return 0;
}
