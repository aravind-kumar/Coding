/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool isValidBST(TreeNode* root) {
        TreeNode* pre = nullptr;
        return isValidBST(root,pre);
    }
    
    
    bool isValidBST(TreeNode* root,TreeNode*& pre) {
        if(root!= nullptr) {
            if(!isValidBST(root->left,pre)) return false;
            if(pre!=nullptr && pre->val >= root->val) return false;
            pre = root;
            return isValidBST(root->right,pre);
        }
        return true;
    }
};
