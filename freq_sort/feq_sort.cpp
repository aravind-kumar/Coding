#include <iostream>
#include <string>
#include <unordered_map>
#include <multiset>
 
string frequencySort(string s) {

    unordered_map<char,int> freqMap;
    
    for(auto&& character : s) 
        freqMap[character]++;
    
    multiset<pair<int,char>> priority_queue;
    
    for(auto&& key_val : freqMap) {
        priority_queue.emplace(key_val.second,key_val.first);
       
    }
    
    string ans="";
    
    for(auto&& it = priority_queue.rbegin();it!=priority_queue.rend();++it) {
            int c = it->first;
            while(c--)
            ans.push_back(it->second);
    }
    
    return ans;
    
}

int main() {
    
    cout<<frequencySort("Aravind");

    return 0;
}
