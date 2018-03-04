#include <iostream>
#include <vector>
struct TreeNode {
    int val;
    left,right *TreeNode;
};

class Solution {
public:
    int tilt=0;
    int SumOfNode(TreeNode* root) {
        if(root==nullptr) {
            return 0;
        }  
        int lSum = SumOfNode(root->left);
        int rSum = SumOfNode(root->right);
        tilt+=abs(lSum-rSum);
        return lSum+rSum+root->val;
    }
    
    int findTilt(TreeNode* root) {
            if(root==nullptr) {
                return 0;
            }
            SumOfNode(root);
            return tilt;
    }
};

int main() {



    return 0;
}
