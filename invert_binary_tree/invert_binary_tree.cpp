#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
  int val;
  TreeNode *left,*right;
};

TreeNode* invertTree(TreeNode* root) {
     TreeNode* newRoot = root;
     invertTreeHelper(root,newRoot);
     return newRoot;    
    }
    
void invertTreeHelper(TreeNode* root,TreeNode&* newRoot) {
    if(root==nullptr) {
        newRoot->left = root->right;
        newRoot->right = root->left;
        invertTreeHelper(root->right,newRoot->left);
        invertTreeHelper(root->left,newRoot->right);
    }
 
}

int main() {



   return 0;

}
