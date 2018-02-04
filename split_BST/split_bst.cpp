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
    vector<TreeNode*> splitBST(TreeNode* root, int V) {      
        vector<TreeNode*> ans;
        TreeNode *current=root,*runner=nullptr;
        bool found=false,isLeft=false;
        while(current!=nullptr && !found) {
            if(current->val > V) {
                isLeft = true;
                runner = current;
                current = current->left;
            } else if(current->val < V) {
                isLeft = false;
                runner = current;
                current = current->right;
            } else {
                found = true;
            }
        }
        if(found && current!=root) {
            if(isLeft) {
                runner->left = current->right;
            } else {
                runner->right = current->right;
            }
            current->right = nullptr;
            ans.push_back(current);
            ans.push_back(root);
        } else if (found && current==root) {
            TreeNode* newRoot = current->right;
            current->right = nullptr;
            ans.push_back(current);
            ans.push_back(newRoot);
        } else {
            ans.push_back(root);
            ans.push_back(nullptr);
        }
        return ans;        
    }
};

