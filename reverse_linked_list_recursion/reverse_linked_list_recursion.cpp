#include <iostream>
template <typename T>
struct Node
{
   T data;
   Node* next;
};


Node* reverseLinkedList(Node* head)
{
   if(head==nullptr || head->next == nullptr) 
      return head;
   else
   {
      Node* nextNode = reverseLinkedList(head->next);
      head->next->next = nextNode;
      head->next=nullptr;
      return nextNode;   
   }

}

int main()
{
   Node<int> head= new Node();
   Node<int> node1= new Node();
   Node<int> node2= new Node();
   Node<int> node3= new Node();
   head->data = 1;
   node1->data = 2;
   node2->data = 3;
   node3->data = 4;
   head->next = node1;
   node1->next = node2;
   node2->next = node3;
   
   
   return 0;
}
