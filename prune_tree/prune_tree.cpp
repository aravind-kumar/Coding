#include <iostream>
//Remove a substree it doesnt have a 1 in it
// use dfs to check if has a 1 it so do nothing otherwise remove it.

class Solution {
public:
    bool pruneTreeHelper(TreeNode* root) {
        if(root!=nullptr) {
               bool leftSub = pruneTreeHelper(root->left);
               if(!leftSub) {
                   root->left = nullptr;
               } 
               bool rightSub = pruneTreeHelper(root->right);
               if(!rightSub) {
                   root->right = nullptr;
               }
               return root->val || leftSub || rightSub;
        }
        return false;
    }
    
    TreeNode* pruneTree(TreeNode* root) {
        
        pruneTreeHelper(root);
            
        return root;
    }
};

int main() {


    return 0;
}
