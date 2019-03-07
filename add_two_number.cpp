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
        ListNode temp(INT_MAX);
        ListNode* newHead = &temp;
        ListNode* tail = &temp;
        int carry = 0;
        while(l1 != nullptr || l2 != nullptr || carry) {
            int num1 = l1 == nullptr ? 0 : l1->val;
            int num2 = l2 == nullptr ? 0 : l2->val;
            int sum = num1+num2+carry;
            tail->next = new ListNode(sum%10);
            tail = tail->next;
            carry = sum/10;
            l1 = l1 == nullptr ? nullptr : l1->next;
            l2 = l2 == nullptr ? nullptr : l2->next;
        }
        return newHead->next; 
    }
};
