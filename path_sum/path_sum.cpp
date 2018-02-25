#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left,right;
};

class Solution {
public:
    void pathSumHelper(TreeNode* root,vector<int> intermediate,vector<vector<int>>& ans,int sum){
        if(root!=nullptr) {
            sum-=root->val;
            intermediate.push_back(root->val);
            pathSumHelper(root->left,intermediate,ans,sum);
            pathSumHelper(root->right,intermediate,ans,sum);
            if(root->left == nullptr && root->right == nullptr && !sum) {
                ans.push_back(intermediate);
            }
        }
    }
    
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<int> intermediate;
        vector<vector<int>> ans;
        pathSumHelper(root,intermediate,ans,sum);
        return ans;
        
    }
};


int main()  {


    return 0;
}
