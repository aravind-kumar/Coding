#include <iostream>

struct TreeNode {
   int val;
   TreeNode* left;
   TreeNode* right;
};

class Solution {
public:
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        if(root==nullptr || p == nullptr) 
            return nullptr;
        if(p->val >= root->val)
            return inorderSuccessor(root->right,p);
        else {
            auto sucessor = inorderSuccessor(root->left,p);
            return sucessor == nullptr ? root : sucessor;
        }
        
        
    }
};
