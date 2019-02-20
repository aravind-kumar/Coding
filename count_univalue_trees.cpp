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
    int countUnivalSubtrees(TreeNode* root) {
        int count = 0;
        
        countUnivalSubtrees(root,count);
        return count;
    }
    
    bool countUnivalSubtrees(TreeNode* root,int& count) {
        if(root != nullptr) {
        
            bool lval = countUnivalSubtrees(root->left,count);
            bool rval = countUnivalSubtrees(root->right,count);
            if(lval == rval) {
                if(root->left != nullptr && root->left->val != root->val) {
                    return false;
                }
                if(root->right != nullptr && root->right->val != root->val) {
                    return false;
                } 
                count++;
                return true;
            }
            return false;
        }
        return true;
    }
};
