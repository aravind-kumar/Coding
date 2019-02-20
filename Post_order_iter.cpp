class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        
        list<int> result;
        stack<TreeNode*> nextNodes;
         while(root != nullptr || !nextNodes.empty()) {
             if(root != nullptr) {
                 result.push_front(root->val);
                 nextNodes.push(root);
                 root = root->right;
             } else {
                 while(root == nullptr && !nextNodes.empty()) {
                     root = nextNodes.top();
                     nextNodes.pop();
                 }
                 root = root->left;
             }
             
         }
        return {result.begin(),result.end()};
        
    }
};
