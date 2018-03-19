#include <iostream>
#include <string>
#include <vector>

using namespace std;

int firstUniqChar(string s) {
        vector<int> freq(26,0);
        for(int i=0;i<s.size();++i) freq[s[i]-'a']+=1;
        
        for(int i=0;i<s.size();++i) if(freq[s[i]-'a']==1) return i;
        
        return -1;
}


int main() {

    cout<<"\n First unique character index"<<firstUniqChar("leetcode");   
    return 0;
}
