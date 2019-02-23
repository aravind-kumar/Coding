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
    TreeNode* invertTree(TreeNode*& root) {
        if(root == nullptr) return nullptr;
        auto temp = root->left;
        root->left = root->right;
        root->right = temp;
        invertTree(root->left);
        invertTree(root->right);
        return root;
    }
};
// Inverting a BT , swapping the left subtree with the right subtree and then continuing on.
// Note that the values cannot be changed and rather the links themselves have to be changed.
// Changing only the values at that level would lead to incorrect behaviour (check the leetcode example).
// We want to change the subtree and then change invert on the new changed trees rather than the old ones.
