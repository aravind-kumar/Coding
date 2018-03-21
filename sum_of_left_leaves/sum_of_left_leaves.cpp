#include <iostream>

struct TreeNode {
   int val;
   TreeNode *left,*right;
};


void sumOfLeftLeavesHelper(TreeNode* node,bool isLeft,int& sum) {
        if(node!=nullptr) {
            if(isLeft && node->left == nullptr && node->right == nullptr) 
                sum+=node->val;
            sumOfLeftLeavesHelper(node->left,true,sum);
            sumOfLeftLeavesHelper(node->right,false,sum);
        }
    }

int sumOfLeftLeaves(TreeNode* root) {
    int sum = 0;
    if(root!=nullptr) {
        bool isLeft = false;
        sumOfLeftLeavesHelper(root,isLeft,sum);    
    }
    return sum;
}


int main() {


    return 0;
}
