class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        
        vector<int> result;
        stack<TreeNode*> stackNodes;
        
        while(root != nullptr || !stackNodes.empty()) {
            if(root != nullptr) {
                result.push_back(root->val);
                stackNodes.push(root);
                root = root->left;
            } else {
                while(root == nullptr && !stackNodes.empty()) {
                    root = stackNodes.top();
                    stackNodes.pop();
                }
                root = root->right;
            }
        }
        
        return result;
    }
};
