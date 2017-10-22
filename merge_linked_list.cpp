#include <iostream>
using namespace std;

struct Node
{
   int num;
   Node *next;
};

void appendNode(Node*& newHead,Node*& tail,Node* addList)
{
  if(newHead == nullptr && tail == nullptr)
  {
      newHead = tail = addList; 
  } 
  else
  {
       tail->next = addList;
  }
}

Node* Merge(Node* L1,Node* L2)
{
   Node* newHead=nullptr;
   Node* tail=nullptr;
   while(L1 != nullptr 
	 &&
         L2 != nullptr)
        {
          if(L1->num < L2->num)
          {
             appendNode(newHead,tail,L1);  
          }
          else
          {
             appendNode(newHead,tail,L2);  
          }
          L1=L1->next;
          L2=L2->next;
        }
   return newHead;
}

int main()
{
  Node* L1 = new Node();
  return 0;
}
