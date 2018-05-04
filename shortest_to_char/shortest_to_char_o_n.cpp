#include <iostream>
#include <vector>
#include <string>

using namespace std;


// Earlier we performed two scans right and left togther for each position
// In this case we perform a left scan first and store the values
// Then we perform a right scan and find the minimum of both of the values


vector<int> shortestToChar(string S, char C) {
    if(S.empty()) return {};
    vector<int> result(S.size(),S.size());
    int pos = -S.size();
    for(int i=0;i<S.size();++i) {
        if(S[i]==C) pos = i;
        result[i] = min(result[i],abs(i-pos));
    }
    
    for(int i=S.size()-1;i>=0;i--) {
        if(S[i]==C) pos = i;
        result[i] = min(result[i],abs(i-pos));
    }
    
    return result;
    
}

int main() {



    return 0;
}
