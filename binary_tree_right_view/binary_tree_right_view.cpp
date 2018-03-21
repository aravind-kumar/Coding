#include <iostream>
#include <unordered_map>
#include <vector>


// Given a BT we have to print the nodes which are viewed from the right side of the nodes.
// We use BFS and use a map to store the nodes.
// The nodes that are last visited are the ones which are right visible.

using namespace std;

    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        
        if(root!=nullptr) {    
            queue<pair<TreeNode*,int>> nextNodes;
            nextNodes.push({root,0});
            
            while(!nextNodes.empty()) {
                queue<pair<TreeNode*,int>> tempNodes;
                unordered_map<int,int> rightNodes;
                
                while(!nextNodes.empty()) {
                    auto top = nextNodes.front() ; nextNodes.pop();
                    
                    rightNodes[top.second] = top.first->val;
                
                    int depth = top.second;
                    
                    if(top.first->left != nullptr) 
                        tempNodes.push({top.first->left,depth+1});
                    if(top.first->right != nullptr) 
                        tempNodes.push({top.first->right,depth+1});
                }
                
                for(auto&& val : rightNodes) 
                    ans.push_back(val.second);
                
                nextNodes = tempNodes;
            }
            
            
        }
        return ans;
    }
};


int main() {




    return 0;
}
