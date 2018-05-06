#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<vector<int>> largeGroupPositions(string S) {
        vector<vector<int>> result;

        for(int i=0;i<S.size();){
            int j=i+1;
            while(j<S.size() && S[i]==S[j]) {
                ++j;
            }
            if(j-i >= 3) {
                result.push_back({i,j-1});
            }
            i=j;
        }
        return result;
        
    }

int main() {



    return 0;
}
