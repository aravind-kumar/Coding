#include <iostream>
#include <map>
#include <vector>

using namespace std;

struct TreeNode {

    int data;
    TreeNode *left,*right;

};

void performBFS(TreeNode* root,map<int,vector<int>>& coodMap) {
        queue<pair<TreeNode*,int>> nextNodes;
        nextNodes.push({root,0});
        while(!nextNodes.empty()){
            auto top = nextNodes.front() ; nextNodes.pop();
            coodMap[top.second].push_back(top.first->val);
            if(top.first->left != nullptr) {
                nextNodes.push({top.first->left,top.second-1});
            } 
            if(top.first->right != nullptr) {
                nextNodes.push({top.first->right,top.second+1});
            }   
        }
    }
    
    vector<vector<int>> verticalOrder(TreeNode* root) {
        pair<int,int> cood = {0,0};
        vector<vector<int>> ans;

        if(root==nullptr) return ans;

        map<int,vector<int>> coodMap;
        performBFS(root,coodMap);
        for(auto coods : coodMap) ans.push_back(coods.second);
        return ans;
    }


int main() {



    return 0;
}
