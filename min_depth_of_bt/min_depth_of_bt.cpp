#include <iostream>
#include <queue>

struct TreeNode {

     int val;
     TreeNode *left;
     TreeNode *right;
};

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
    int minDepth(TreeNode* root) {
       
        if(root!=nullptr) {
            typedef pair<TreeNode*,int> nodeCount;
            queue<nodeCount> bfs;
            bfs.push({root,1});
            while(!bfs.empty()) {
                auto top = bfs.front();
                bfs.pop();
                if(top.first->left == nullptr && top.first->right == nullptr) 
                    return top.second;
                if (top.first->left != nullptr)
                    bfs.push({top.first->left,top.second+1});
                if (top.first->right != nullptr) 
                    bfs.push({top.first->right,top.second+1});
                
            }
        }
        return 0;
        
    }
};
