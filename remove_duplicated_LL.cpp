#include <iostream>
#include <unordered_map>

using namespace std;
template<typename T>
struct Node
{
   T data;
   shared_ptr<Node> next;
   Node(T data)
   {
      this->data=data;
      next=nullptr;
   }
};

template<typename T>
void LLMapper(shared_ptr<Node<T>> head,function<void(T)> fn) 
{
   shared_ptr<Node<T>> current(head);
   while(current != nullptr) {
      fn(current->data);
      current = current->next;
   }
     
}
template<typename T>
shared_ptr<Node<T>> unique(shared_ptr<Node<T>> head)
{
  shared_ptr<Node<T>> current = head;
  shared_ptr<Node<T>> prev = nullptr;
  unordered_map<T,bool> nodeMap;
  while(current!= nullptr)
  {
     if(nodeMap.find(current->data) != nodeMap.end())
     {
        shared_ptr<Node<T>> temp = current->next;
        prev->next = current->next;
        current->next = nullptr;
        current = temp;
        continue;
     }
     else
        nodeMap[current->data] = true;
     prev=current; 
     current = current->next; 
  } 
  
  cout<<"\n New nodes are";
  LLMapper<int>(head,[](int data) { cout<<data<<"--->";}); 
  return nullptr;
}


int main()
{
   shared_ptr<Node<int>> head=nullptr;
   shared_ptr<Node<int>> tail=nullptr;

   int num;
   cout<<"\n Enter the number of nodes";
   cin>>num;
   for(int i=0;i<num;++i)
   {
      int givenNum;
      cin>>givenNum;
      shared_ptr<Node<int>> newNode(new Node<int>(givenNum));
      if(head==nullptr)
        head=tail=newNode;
      else
      {  
        tail->next=newNode;
        tail=newNode;
      }  
   }
   LLMapper<int>(head,[](int data) { cout<<data<<"--->";});
   shared_ptr<Node<int>> unique_head =  unique<int>(head);
   return 0;
}
