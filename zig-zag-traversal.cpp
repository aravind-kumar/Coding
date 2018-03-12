#include <iostream>
#include <vector>
#include <algorithms>
#include <queue>

using namespace std;

struct TreeNode {
      int val;
      TreeNode *left,*right;
      
      TreeNode(int data) {
        this->val = data;
        left = right = nullptr;
      }
};

vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> result;
        if(root==nullptr) return result;
        
        queue<TreeNode*> nextNodes;
        nextNodes.push(root);
        
        int order = 0;
        
        while(!nextNodes.empty()) {

            vector<int> ans;
            queue<TreeNode*> newNodes;
            
            while(!nextNodes.empty()) {
                auto topNode = nextNodes.front(); 
                nextNodes.pop();
                
                if(topNode->left!=nullptr) newNodes.push(topNode->left);
                if(topNode->right!=nullptr) newNodes.push(topNode->right);
                
                ans.push_back(topNode->val);
            }
            
            nextNodes = newNodes;
            
            if(order & 1) reverse(ans.begin(),ans.end());
            
            result.push_back(ans);
            ++order;
        }
        
        return result;
        
    }
