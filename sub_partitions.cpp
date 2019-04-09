class Solution {
public:
    vector<int> partitionLabels(string S) {
        if(S == "") return {};
        
        vector<int> result;
        vector<int> lastIndex(26);
        for(int i=0;i<S.size();++i) {
            lastIndex[S[i]-'a'] = i;
        }
        int start = 0,last = 0;
        for(int i=0;i<S.size();++i) {
            last = max(last,lastIndex[S[i]-'a']);
            if(i == last) {
                result.push_back(last-start+1);
                start = last+1;
            }
        }
        
        return result;
        
    }
};
