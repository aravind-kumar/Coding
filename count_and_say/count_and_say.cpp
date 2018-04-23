#include <iostream>
#include <string>

string getNextNum(string input) {
    string output="";
    int i=0;
    while(i<input.size()) {
        int count = 1;
        int j=i+1;
        while(j<input.size() && input[j]==input[i]) {
            count++;
            ++j;
        }
        string result = to_string(count);
        result.push_back(input[i]);
        i=j;
        output+=result;
    }
    
    return output;
}

string countAndSay(int n) {
    if(n<=0) return "";
    
    string result = "1";
    for(int i=1;i<n;++i) {
        result = getNextNum(result);
    }
    
    return result;
    
}

int main() {


    return 0;
}
