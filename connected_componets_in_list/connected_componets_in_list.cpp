#include <iostream>
class Solution {
public:
    int numComponents(ListNode* head, vector<int>& G) {
        vector<pair<int,bool>> numVisited;
        ListNode* current = head;
        while(current!=nullptr) {
           numVisited.push_back({current->val,false});
            current = current->next;
        }
        
        for(int num : G) {
            pair<int,bool> number{num,false};
            vector<pair<int,bool>>::iterator it = find(numVisited.begin(),numVisited.end(),number);
            it->second=true;
        }
        
        int connectedComponents = 0;
        bool val = false;
        for(auto&& visitedNums : numVisited) {
            if(val == false && visitedNums.second) {
                val = true;
                ++connectedComponents;
            } else if(!visitedNums.second) {
                val = false;
            }
        }
        
        return connectedComponents;
        
    }
};


int main() {



    return 0;
}
