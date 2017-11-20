#include <iostream>

using namespace std;

struct Node
{
   int data;   
   shared_ptr<Node> next;
};


typedef shared_ptr<Node> NodePtr;

int GetLen(NodePtr head)
{
   int count=0;
   while(head!=nullptr)
   {
      ++count;
   }
   return count;
}

void Increment(shared_ptr<Node>& head,int num)
{
     while(head!=nullptr && num)
     {
        --num;
        head=head->next; 
     }
}

NodePtr GetIntersectingNode(NodePtr head,NodePtr head2)
{
    int len1 = GetLen(head);
    int len2 = GetLen(head2);
    if(len1 < len2)
    { 
        Increment(head2,(len2-len1));
    }
    else
    {
        Increment(head,(len1-len2));
    } 
    
    while(head!=head2) 
    {
        head=head->next;
        head2=head2->next; 
    } 
    return head;
}

int main()
{
   return 0;
}
