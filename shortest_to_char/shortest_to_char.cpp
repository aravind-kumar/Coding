#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<int> shortestToChar(string S, char C) {            
        if(S.empty()) return {};
        
        vector<int> result(S.size(),0);   
        for(int i=0;i<S.size();++i) {
            if(S[i]!=C) {
                int left=INT_MAX,right=INT_MAX;
                for(int j=i;j<S.size();++j) {
                    if(S[j] == C) {
                        right = j;
                        break;
                    }        
                } 
                for(int j=i;j>=0;--j) {
                    if(S[j] == C){
                        left = j;
                        break;
                    }        
                } 
                right = right!=INT_MAX ? right = right - i : INT_MAX;
                left = left!=INT_MAX ? i-left : INT_MAX;
                result[i] = min(left,right);
            }
        }
        
        return result;
}

int main() {




    return 0;
}
