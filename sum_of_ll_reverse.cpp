/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        stack<int> num1;
        stack<int> num2;
        int carry = 0;
        int sum = 0;
        ListNode* result = nullptr;
        
        while(l1!=nullptr) {
            num1.push(l1->val);
            l1=l1->next;
        }
        
        while(l2!=nullptr){
            num2.push(l2->val);
            l2 = l2->next;
        }
        
        while(!num1.empty() || !num2.empty() || carry) {
            int first,second;
            
            if(!num1.empty()) {
                first = num1.top();
                num1.pop();
            } else {
                first = 0;
            }
            
            if(!num2.empty()) {
                second = num2.top();
                num2.pop();
            } else {
                second = 0;
            }
            sum = first+second+carry; 
            
            carry = sum/10;
            
            int num = sum%10;
            
            if(result == nullptr) {
                result = new ListNode(num);
            } else {
                ListNode *temp = new ListNode(num);
                temp->next = result;
                result = temp;
            }
        
        }
        
        return result;
        
    }
};


int main() {




return 0;
}
