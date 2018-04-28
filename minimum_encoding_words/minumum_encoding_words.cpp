#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>


int minimumLengthEncoding(vector<string>& words) {
        unordered_set<string> unique_words(words.begin(),words.end());
        
        for(auto word : unique_words) {
            for(int i=1;i<word.size();++i){
                unique_words.erase(word.substr(i));
            }
        }
        
        int len=0;
        for(auto&& word : unique_words) {
           len+=word.size()+1;
        }
        return len;
    }


int main() {




    return 0;
}
