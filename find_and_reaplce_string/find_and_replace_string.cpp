#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
#include <utility>

using namespace std;

bool isMatch(string input,int start,string pattern) {
        int i=start,j=0;
        while(i<input.size() && j<pattern.size()) {
            if(input[i]!=pattern[j]) {
                return false;
            }
            ++i;
            ++j;
        }
        return true;
    }
        
    string findReplaceString(string S, vector<int>& indexes, vector<string>& sources, vector<string>& targets) {
        
        string result="";
        
        map<int,vector<string>> indexMap;
        
        for(int i=0;i<indexes.size();++i) {
            indexMap[indexes[i]].push_back(sources[i]);
            indexMap[indexes[i]].push_back(targets[i]);
        }
        
        for(int i=0;i<S.size();++i) {
            auto found = indexMap.find(i);
          
            if(found !=indexMap.end() && isMatch(S,i,indexMap[i].front())) {
                input+=pattern; 
                i += indexMap[i].front().length()-1;
            } else {
                result.push_back(S[i]);
             
            }
        }
   
        return result;
    }


int main() {



    return 0;
}
