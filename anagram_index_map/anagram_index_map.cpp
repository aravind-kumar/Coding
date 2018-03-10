#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;


vector<int> findAnagramIndexMap(vector<int> input1,vector<int> input2) {
     vector<int> output;

     unordered_map<int,int> charIndexMap;
     for(int i=0;i<input2.size();++i) {
         charIndexMap[input2[i]] = i; 
     }
    
     for(int i=0;i<input1.size();++i) {
         output.push_back(charIndexMap[input1[i]]); 
     }
     return output;
}

int main() {
    vector<int> input1;
    vector<int> input2;
    vector<int> output = findAnagramIndexMap(input1,input2);
    for_each(output.begin(),output.end(),[](int input) { cout<<input<<" ";});
}
