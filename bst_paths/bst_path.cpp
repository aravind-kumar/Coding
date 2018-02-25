#include <iostream>
#include <string>

struct TreeNode {
   int val;
   TreeNode* left,right
};

class Solution {
public:
    void bstPathHelper(TreeNode* root,string tempResult,vector<string>& paths) {
        if(root!=nullptr) {
            tempResult+=to_string(root->val);
            //tempResult+= "->";
            bstPathHelper(root->left,tempResult+"->",paths);
            bstPathHelper(root->right,tempResult+"->",paths);
            if(root->left == nullptr && root->right == nullptr){
                
                paths.push_back(tempResult);
            }
        }
        
    }
    
    vector<string> binaryTreePaths(TreeNode* root) {
        
        vector<string> ans;
        bstPathHelper(root,"",ans);
        return ans;
    }
};
  
int main() {



    return 0;
}
