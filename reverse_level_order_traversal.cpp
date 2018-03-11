/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

// Here we are asked to print the level order traversal of BT.
// But heres the catch we have to find print it in revese order i.e bottom up and not top down
// If we use the normal BFS method of printing the nodes then we would have redudant nodes
// Hence at a given level we iterate through all the nodes and push them into the queue at one shot rather than performing
// for a single node at a time.
// By doing so we can keep tack of the nodes at a given level and at the same time perform BFS.

class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> ans;
        
        if(root==nullptr) return ans;
        
        queue<TreeNode*> nextNodes;
        nextNodes.push(root);
        
        while(!nextNodes.empty()) {
            vector<int> level;
            queue<TreeNode*> newQueue;
            
            while(!nextNodes.empty()) {
                auto top = nextNodes.front(); nextNodes.pop();
                level.push_back(top->val);
                if(top->left != nullptr) newQueue.push(top->left);
                if(top->right != nullptr) newQueue.push(top->right);
            }
            nextNodes = newQueue;
            ans.push_back(level);
        }
        reverse(ans.begin(),ans.end());
        return ans;
        
    }
};


int main() {

  
    return 0;
}
