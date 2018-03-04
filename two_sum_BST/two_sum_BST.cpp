#include <iostream>
#include <vector>

struct TreeNode {
 
     int val;
     TreeNode* left,right; 
};

class Solution {
public:
    bool findTarget(TreeNode* root,int k,unordered_set<int>& set) {
        if(root!=nullptr) {
            if(set.find(k-root->val) != set.end()) return true;
            set.insert(root->val);
            return findTarget(root->left,k,set) || findTarget(root->right,k,set);
        }
        return false;
    }
    bool findTarget(TreeNode* root, int k) {
        if(root!=nullptr) {
           unordered_set<int> nodeValues;  
           return findTarget(root,k,nodeValues);
        }
        return k==0;
        
    }
};

int main() {


    return 0;
}
