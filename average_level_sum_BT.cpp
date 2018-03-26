class Solution {
public:
    vector<double> averageOfLevels(TreeNode* root) {
        
        vector<double> ans;
        
        if(root!=nullptr) {
            
            queue<TreeNode*> nextNodes;
            nextNodes.push(root);
            nextNodes.push(nullptr);
                
            double sum = 0,numOfNodes=0;
            while(!nextNodes.empty()) {
                TreeNode* top = nextNodes.front(); nextNodes.pop();
                if(top == nullptr) {
                    ans.emplace_back(sum/numOfNodes);
                    sum=0;
                    numOfNodes=0;
                    if(!nextNodes.empty()) 
                        nextNodes.push(nullptr);
                } else {
                    sum+=top->val;
                    numOfNodes++;
                    if(top->left != nullptr)
                        nextNodes.push(top->left);
                    if(top->right != nullptr)
                        nextNodes.push(top->right);
                }
            }
        }
        return ans;
        
    }
};


int main() {




  return 0;
}
