vector<int> inorderTraversal(TreeNode* root) {
        
        vector<int> result;
        stack<TreeNode*> elements;
        
        while(root!=nullptr || !elements.empty()) {
            if(root!= nullptr) {
                elements.push(root);
                root = root->left;
            } else {
                while(!elements.empty() && root == nullptr) {
                    root = elements.top(); 
                    elements.pop(); 
                    result.push_back(root->val);
                }
                root = root->right;
            }
        }  
        return result;
        
    }
