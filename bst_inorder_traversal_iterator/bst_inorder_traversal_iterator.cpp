#include <iostream>
#include <stack>

class BSTIterator {
    stack<TreeNode*> nextElement;
public:
    void pushLeft(TreeNode *root) {
        while (root!=nullptr) {
            nextElement.push(root);
            root = root->left;
        }
    }
    
    BSTIterator(TreeNode *root) {
        pushLeft(root);    
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
        return !nextElement.empty();
    }

    /** @return the next smallest number */
    int next() {
        auto top = nextElement.top();
        nextElement.pop();
        pushLeft(top->right);
        return top->val;
    }
};


int main() {




}
