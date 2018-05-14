#include <iostream>
#include <vector>

using namespace std;

    void flip(vector<int>& input) {
        for(int i=0;i<input.size();++i) {
            input[i]=!input[i];
        }
    }
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& A) {
        
        vector<vector<int>> result;
        
        for(auto row : A) {
            reverse(row.begin(),row.end());
            flip(row);
            result.push_back(row);
        }
        return result;
        
    }


int main() {


    return 0;
}
