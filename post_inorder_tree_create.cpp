class Solution {
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if(inorder.empty() || postorder.empty()) return nullptr;
        unordered_map<int,int> inIndexMap;
        int n = postorder.size()-1;
        for(int i=0;i<inorder.size();++i) 
            inIndexMap[inorder[i]] = i;
        
        pair<int,int> startEnd = {0,postorder.size()-1};
        return buildTree(inorder,postorder,startEnd,inIndexMap,n);
    }
    
    TreeNode* buildTree(vector<int> inorder,
                   vector<int> postorder,
                   pair<int,int> startEnd,
                   unordered_map<int,int> inIndexMap,
                   int &index) {
        
        if(startEnd.first > startEnd.second || startEnd.second < startEnd.first || index < 0 || index >= postorder.size()) {
            return nullptr;
        }
        
        TreeNode* node = new TreeNode(postorder[index]);
        int inorderIndex = inIndexMap[postorder[index]];
        --index;
        node->right = buildTree(inorder,postorder,{inorderIndex+1,startEnd.second},inIndexMap,index);
        node->left = buildTree(inorder,postorder,{startEnd.first,inorderIndex-1},inIndexMap,index);
        return node;
    }
    
};
