#include <iostream>
#include <stack>
#include <vector>


class Solution {
public:
    bool verifyPreorder(vector<int>& preorder) {
        int low = INT_MIN;
        stack<int> lessThanRootStack;
        for(auto&& num : preorder) {
            if(num<low)
                return false;
            while(!lessThanRootStack.empty() && num > lessThanRootStack.top()) {
                low = lessThanRootStack.top();
                lessThanRootStack.pop();
            }
            lessThanRootStack.push(num);
        }
        return true;
        
    }
};

int main() {



    return 0;
}
