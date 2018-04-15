#include <iostream>

string mostCommonWord(string paragraph, vector<string>& banned) {
        if(paragraph.empty()) return "";
        unordered_set<string> bannedWords;
        for(string word : banned) bannedWords.insert(word);
        unordered_map<string,int> wordCount;
        
        string word = "";
        int maxCount=INT_MIN;
        string maxWord = "";
        
        for(int i=0;i<paragraph.size();++i) {
            if(paragraph[i]!=' ' && isalpha(paragraph[i])) 
                word.push_back(tolower(paragraph[i]));  
            else if(paragraph[i] == ' ' ) {
                if(!bannedWords.count(word)) {
                    int count;
                    if(wordCount.find(word) != wordCount.end()) {
                        wordCount[word]++;
                        count = wordCount[word];     
                    } else {
                        wordCount[word]=1;
                        count = 1;
                    }
                    if(count>maxCount) {    
                        maxCount = count;
                        maxWord = word;
                    }        
            }
            word = "";
        }
    }
        
       return maxCount == INT_MIN ? word : maxWord;
        
}


int main() {


    return 0;
}
