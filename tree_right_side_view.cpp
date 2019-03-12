class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> result;
        int maxDepth = INT_MIN;
        int current = 0;
        rightSideView(root,current,maxDepth,result);
        return result;
    }
    
    void rightSideView(TreeNode* root,int current,int& maxDepth,vector<int>& result) {
        if(root!=nullptr){
            if(current > maxDepth) {
                result.push_back(root->val);
                maxDepth = current;
            }
            rightSideView(root->right,current+1,maxDepth,result);
            rightSideView(root->left,current+1,maxDepth,result); 
        }
    }
};


// Keep going right and keep track of the current depth, if the current Depth is greater than max only then insert.
