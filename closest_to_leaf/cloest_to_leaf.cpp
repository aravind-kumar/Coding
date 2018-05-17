#include <iostream>


int findClosestLeaf(TreeNode* root, int k) {
        if(root!=nullptr) {
            queue<pair<TreeNode*,bool>> children;
            children.push({root,false});
            
            while(!children.empty()) {
                auto top = children.front(); children.pop();
                top.second |= top.first->val == k;
                
                if(top.second && top.first->left == nullptr && top.first->right == nullptr) {
                    return top.first->val;
                } 
                if(top.first->left != nullptr) {
                    children.push({top.first->left,top.second});
                }
                if(top.first->right != nullptr) {
                    children.push({top.first->right,top.second});
                }    
            }  
        }

        return INT_MAX;
    }


int main() {




}
