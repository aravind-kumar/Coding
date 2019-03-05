class Solution {
public:
    bool isValid(string s) {
        int top= -1;
        for(int i=0;i<s.size();++i) {
            if(top < 0 || !isMatch(s[top],s[i])) {
                top++;
                s[top] = s[i];
            } else {
                --top;
            }
        }
        
        return top == -1;
    }
    
    bool isMatch(char c1,char c2) {
        if(c1 == '[' && c2 == ']') return true;
        else if(c1 == '(' && c2 == ')') return true;
        else if(c1 == '{' && c2 == '}') return true;
        return false;
    }
};


// This is a really nice logic to check if the input string has valid parens.
// We make use of (or modify) the input string as a stack (which could be bad if input is passed by reff but its passed by value) and have one pointer called as top.
// The input string's top points to the top of the stack .
// The input string is converted into a stack as time progress i.e when top<0 or when top doesnt match (i.e when we have an opening paren)
// The input string top position is replaced with the current opening bracket.
// When the match is proper match i.e the top being an opening and the ith being a close bracket, we decrement the stack pointer to point to the previous location 
// What if top < 0 during the iterations it could (in cases like ")))))))))))))(" and thats why we have the first check.
// The moment it top becomes less than 0 i.e -1 we take the next input and put it as s[0] it could be an opening or a closing bracket.
// If is a closing bracket then we know for a fact that its going to be invalid.
// Hence we also add the check 
// if(top >=0 && isInvalid(s[top])) break; 
// bool isInvalid(char c1) {
//        return c1 == '}' || c1 == ']' || c1 == ')';
//   }
