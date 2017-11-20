#include <iostream>
#include <assert.h>
using namespace std;

struct Node
{
   int data;
   shared_ptr<Node> next;
};

typedef shared_ptr<Node> NodePtr;

int len(NodePtr head)
{
   int count=0;
   while(head!=nullptr)
       ++count;
   return count;
}

NodePtr Increment(NodePtr head,int num)
{
   while(head!=nullptr && num)
   {
      head=head->next;
      --num;
   }
   return head;
}

NodePtr RemoveKthElement(NodePtr head,int k)
{ 
   assert(k>=0 && k<(len(head)));
    
   NodePtr slow = head;
   NodePtr prevSlow = head;
   NodePtr fast = Increment(head,k);
   while(fast!=nullptr)
   {
      prevSlow = slow;
      slow = slow->next;
      fast = fast->next; 
   }
   prevSlow->next = slow->next;
   return head;
}

int main()
{


   return 0;
}
