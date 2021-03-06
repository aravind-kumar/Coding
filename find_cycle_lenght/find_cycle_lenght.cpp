#include <iostream>
#include <assert.h>
using namespace std;

struct Node
{
    int num;
    Node *next;
};

int FindCycleLength(Node* head)
{
    int cycleLength = 0;
    if(head!= nullptr && head->next!=nullptr)
    {
        Node* slow,*fast; 
        slow=head;
        fast=head->next->next;
        while(slow!=nullptr && head!=nullptr && head->next!=nullptr)
        {
           if(slow == fast) break;
           slow = slow->next;
           fast = fast->next->next;
        }
        if(slow!=nullptr && fast!=nullptr && fast->next!=nullptr)
        {
            assert(slow==fast);
            Node* current = fast; 
            while(current->next != fast)
            {
               ++cycleLength; 
               current=current->next;
            }
        }
    }
    return cycleLength;
}

int main()
{

   return 0;
}
