class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        return swapPairs(head,0);
        
    }
    
    ListNode* swapPairs(ListNode* head,int k) {
        if(head == nullptr || head->next == nullptr) 
            return head;
        k++;
        head->next = swapPairs(head->next,k);
        if(k%2 == 1) {
            auto first = head;
            auto second = head->next;
            auto third = head->next->next;
            second->next = first;
            first->next = third;
            head = second;
        } 
        return head;
    }
};

// we swap nodes in pairs, we know if the current and the next nodes need to be swapped by using the value k .
// if k is odd then we know that the current and the next nodes need to be swapped.
// The head == nullptr || head->next == nullptr are checks which are used to check if we have reached the last nodes or if we have last but one node
// In those cases we have nothing to reverse, so we just return the node.
// we increment k and then pass the new k and the next pointer to the swapPairs function
// Whatever is returned from swapPairs is the newHead of the swapped list of number.
// We point the next of the current(head) to the swapped pair list.
// If we know that we are at even number we just return the head.
// Otherwise if we know that we are odd (i.e we have swap the current and the next node)/
// We swap them and assign a new head and return that.
