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
    TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
        TreeNode* root=nullptr;
        if(t1 !=nullptr || t2 != nullptr) { // If either one of them exists.
            
            int t1Data = t1 == nullptr ? 0 : t1->val;
            int t2Data = t2 == nullptr ? 0 : t2->val;
            
            root = new TreeNode(t1Data+t2Data);
            
            auto t1Left = t1 == nullptr ? nullptr : t1->left;
            auto t1Right = t1 == nullptr ? nullptr : t1->right;
            auto t2Left = t2 == nullptr ? nullptr : t2->left;
            auto t2Right = t2 == nullptr ? nullptr : t2->right;
            
            root->left = mergeTrees(t1Left,t2Left);
            root->right = mergeTrees(t1Right,t2Right);
            return root;
        } 
        return root;
        
    }
};


int main() {

  Solution s;
  

   return 0;
}
