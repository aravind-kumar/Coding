#include <iostream>
#include <assert.h>

using namespace std;

struct Node
{
   int num;
   Node* next;

};
Node* getHead(Node* current)
{
    while(current->num<current->next->num)
    {
        current=current->next;
    }
    return current;
}

int getCountAndCheckIdentical(Node* head,bool& isIdentical)
{
   int count=0;
   Node* current = head;
   while(current!=nullptr)
   {
      isIdentical = isIdentical && (current->num == current->next->num);
      ++count;
      current = current->next;
   }
   return count; 
}

int findMedian(Node* head,int length)
{
    Node* current = head;
    while(length)
    {  
       current = current->next;
       --length; 
    }
    return current->num;
}

int find_median(Node* head)
{
   int median = 0;
   if(head!=nullptr) 
   {
      Node* newHead = getHead(head)->next;
      bool isIdentical=true;
      int length = getCountAndCheckIdentical(newHead,isIdentical);
      if(isIdentical)
      {
          median = head->num;
      } 
      else
      {
         median = findMedian(head,length); 
      }
   }
   return median;

}

int main()
{
   return 0;
}
