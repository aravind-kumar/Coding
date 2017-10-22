#include <iostream>
using namespace std;

struct Node
{
   int num;
   Node* next;
};

Node* CheckIfCycleExsists(Node* head)
{ 
   if(head->next!=nullptr)
   {
       Node* slow,fast;
       slow = head;
       fast = head->next->next;
       while(slow!=nullptr && fast->next != nullptr)
       {
          if(slow == head) break; 
          slow=slow->next;
          fast=fast->next->next;   
       } 
       if(slow != nullptr || fast != nullptr)
       {
          slow = head;
          while(slow->next != fast->next)
          {
             slow = slow->next;
             fast = fast->next;
          } 
       }
       return slow;
  }
  return nullptr;
}

int main()
{


   return 0;
}
