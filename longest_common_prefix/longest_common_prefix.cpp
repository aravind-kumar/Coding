#include <utility>
#include <vector>
#include <string>
#include <algorithm>

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.size()) {
            auto LCP = [](string acc,string input) {
                if(acc.size() > input.size()) 
                     swap(acc,input);
                return string(acc.begin(),
                              mismatch(acc.begin(),acc.end(),input.begin()).first);
            };  
            return accumulate(strs.begin(),strs.end(),strs.front(),LCP);    
        }
        return "";
        
    }
};


int main()
{
    Solution s;
    int num;
    vector<string> input;
    cout<<"\n Enter the number of strings";    
    cin>>num;
    for(int i=0;i<num;++i) {
        string inputString;
        cout<<"\n Enter the string";
        cin>>inputString; 
        input.push_back(inputString);
    }
    cout<<"\n The longest substring is "<<s.longestCommonPrefix(input);

    return 0;
}
