#include <iostream>

class Node
{
   Node* left;
   Node* right;
   Node* parent;
   bool isNodeLocked;
   int numOfChildrenLocked;

   bool isLocked()
   {
      return isNodeLocked;
   }
   
   int getNumOfChildrenLocked()
   { 
      return numOfChildrenLocked;
   }
   
   void setNumOfChildrenLocked(int newCount)
   {
      numOfChildrenLocked = newCount; 
   }
 
   bool lock()
   {
      if(!isNodeLocked && !numOfChildrenLocked)
      {
         Node* current = parent;
         while(current!=nullptr)
         {
            if(current->isLocked())
		return false;
            current=current->parent;
         }  

         isNodeLocked=true;
         numOfChildrenLocked++;
         current = parent;

         while(current!=nullptr)
         {
            int currentLocks = current->getNumOfChildrenLocked();
            current->setNumOfChildrenLocked(currentLocks+1);
            current=current->parent;
         }
         return true; 
      }
      return false;
   }
   
   bool unlock()
   {
     if(isNodeLocked)
     {
       isNodeLocked = false;
       Node* current = parent;
       while(current != nullptr)
       {
          int currentLocks = current->getNumOfChildrenLocked();
          current->setNumOfChildrenLocked(currentLocks-1);
          current = current->parent;
       } 
       return true;
     } 
     return false;
   }
};

int main()
{

   return 0;
}
