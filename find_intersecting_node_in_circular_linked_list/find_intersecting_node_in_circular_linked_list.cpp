#include <iostream>
#include <assert.h>
  
using namespace std;

struct Node
{
   int data;
   shared_ptr<Node> next;
};

typedef shared_ptr<Node> NodePtr;

int getLen(NodePtr L1,NodePtr endPtr = nullptr)
{ 
   int count = 0;
   while(L1 != endPtr)
   {
      ++count;
   } 
   return count;
}

NodePtr Increment(NodePtr input,int num)
{
     while(num-- && input != nullptr)
         input = input->next;
     return input;
}


NodePtr checkForCycle(NodePtr L1)
{  
   NodePtr slow,fast; 
   while(slow!=nullptr && fast!=nullptr && fast->next!=nullptr)
   {
     
     if(slow == fast) break;

     slow = slow->next;
     fast = fast->next->next;
   }
   if(slow==nullptr || fast == nullptr || fast->next==nullptr)
      return nullptr;
   return slow;
}

NodePtr getIntersectingNode(NodePtr L1,NodePtr L2,
		            unsigned int lenOfL1,
		            unsigned int lenOfL2)
{
     if(lenOfL1 < lenOfL2)
     	L1=Increment(L1,lenOfL2-lenOfL1);
     else 
        L2=Increment(L2,lenOfL1-lenOfL2);
    
     while(L1!=L2)
     {
        L1 = L1->next;
        L2 = L2->next;
     }     
     return L1;
}

NodePtr getStartOfCycle(NodePtr head,NodePtr intersectingNode)
{
   while(head!=intersectingNode)
   {
      head=head->next;
      intersectingNode = intersectingNode->next;
   }
   return intersectingNode;
}

NodePtr FindIntersectingNode(NodePtr L1, NodePtr L2)
{
   if(L1!=nullptr && L2!=nullptr)
   {
      NodePtr doesL1HaveCycle = checkForCycle(L1);
      NodePtr doesL2HaveCycle = checkForCycle(L2);
      if(doesL1HaveCycle!=nullptr && doesL2HaveCycle!=nullptr) 
      {
          NodePtr cycleStartPtr = getStartOfCycle(L1,doesL1HaveCycle);
          int lenOfL1 = getLen(L1,cycleStartPtr);
          int lenOfL2 = getLen(L2,cycleStartPtr);
          return getIntersectingNode(L1,L2,lenOfL1,lenOfL2);
      } 
      else if (doesL1HaveCycle == nullptr && doesL2HaveCycle == nullptr)
      {
         int lenOfL1 = getLen(L1);
         int lenOfL2 = getLen(L2); 
         return getIntersectingNode(L1,L2,lenOfL1,lenOfL2);
      } 
   }
   return nullptr;
}

int main()
{

   return 0;
}
