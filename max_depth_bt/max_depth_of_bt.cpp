#include <iostream>
struct TreeNode {

    int data;
    TreeNode* left,right;
};

class Solution {
public:
    int maxDepth(TreeNode* root) {
        if (root!=nullptr) {
            int lHeight = maxDepth(root->left);
            int rHeight = maxDepth(root->right);
            return max(lHeight,rHeight) + 1;
        }
        return 0;
    }
};

int main() {



    return 0;
}

