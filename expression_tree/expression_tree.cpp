#include <iostream>
#include <vector>
#include <algorithms>
#include <string>
#include <utility>

template <class T>
class Node
{
  private:
    T num;
    Node* left;
    Node* right; 
  public:
    Node()
    {
       left = right = NULL
    }
    Node(T num)
    {
       this->num = num;
    }
    T getNum()
    {
       return num;
    }
};

class Tree
{ 
   private:
      Node* root;
   public:
      Tree()
      {
         root=NULL;
      } 
      void insertNodeLeft(T element)
      { 
           
      }
      void buildTree(string inputString)
      {
         for(auto&& element : inputString)
         {
            if(operator(element))
              insertNode(element); 
         }
      }
};
