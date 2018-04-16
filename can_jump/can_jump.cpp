#include <iostream>
#include <vector>
//use dfs to check if a node is reachable

vector<int> validChildren(int index,vector<int> input) {
        vector<int> children;
        for(int i=index+1,j=input[index];i<input.size() && j>0;++i,--j) {
            children.push_back(i);
        }   
        return children;
    }
    bool canJump(vector<int>& nums) { 
        if(nums.empty()) 
            return false;
        if(nums.size()==1 && nums.front()>=0) 
            return true;
        
        stack<int> toVisit;
        toVisit.push(0);
        
        while(!toVisit.empty()) {
            int top = toVisit.top() ; toVisit.pop();
            for(int i : validChildren(top,nums)) {
                if(i == nums.size()-1) 
                    return true;
                toVisit.push(i);
            }
        }
        return false;
        
        
    }


int main() {



    return 0;
}
