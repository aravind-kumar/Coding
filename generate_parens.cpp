class Solution {
public:
    vector<string> generateParenthesis(int n) {
        unordered_set<string> result;
        string input = "";
        generateParens(n,n,input,result); 
        return {result.begin(),result.end()};
        
    }
    
    void generateParens(int startC,int endC,string input,unordered_set<string>& result) {
        //cout<<input<<endl;
        if(startC == endC && endC == 0) {
            result.insert(input);
        }
        while(startC) {
            input.push_back('(');
            startC--;
            generateParens(startC,endC,input,result);
            while(endC && endC>startC) {
                input.push_back(')');
                endC--;
                generateParens(startC,endC,input,result);   
            }
        }      
    }
};


// We are given two choices at every step either open or close but we can only close if there are open 
// We use a backtracking solution to solve the problem.
// However the problem with backtracking is that we are generating duplicates in this solution.
// We have to prevent that from happening.
// One ugly hack is to use a unordered_set but we should not produce duplicates in the first place.
// Find a way to fix that
