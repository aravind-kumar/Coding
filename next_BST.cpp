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
    TreeNode* convertBST(TreeNode* root) {
        TreeNode* lastNode = nullptr;
        convertBST(root,lastNode);
        return root;
    }
    
    void convertBST(TreeNode*& root,TreeNode*& lastNode) {
        if(root != nullptr) {
            convertBST(root->right,lastNode);
            if(lastNode!=nullptr) {
                root->val+=lastNode->val;   
            }
            lastNode=root;
            convertBST(root->left,lastNode);
        }
    }
};
