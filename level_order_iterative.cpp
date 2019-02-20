class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> result;
        
        if(root!= nullptr) {
            queue<TreeNode*> nextNodes;
            vector<int> intermediate;
            nextNodes.push(root);
            nextNodes.push(nullptr);
            while(!nextNodes.empty()) {
                auto nextNode = nextNodes.front();
                nextNodes.pop();
                if(nextNode != nullptr) {
                    intermediate.push_back(nextNode->val);
                    if(nextNode->left != nullptr) {
                        nextNodes.push(nextNode->left);
                    }
                    if(nextNode->right != nullptr) {
                        nextNodes.push(nextNode->right);
                    }
                } else {
                    result.push_back(intermediate);
                    intermediate.clear();
                    if(!nextNodes.empty()) {
                        nextNodes.push(nullptr);
                    }
                }
            }
        }
        
        
        return result;
        
    }
};
