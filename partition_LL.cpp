#include <iostream>

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
template <typename T>
void partition(shared_ptr<Node<T>> head,T data)
{
   shared_ptr<Node<T>> wall=head,current=head,prev=head;
   while(current!= nullptr)
   {
       if(current->data < data)
       {
            shared_ptr<Node<T>> wallNext = wall->next;
            wall->next = current;
            prev->next = current->next;
            current->next = wallNext;
            wall = current;
            current= prev->next;      
            continue;
       }
       prev = current;
       current = current->next;
   }
   LLMapper<int>(head,[](int data) { cout<<data<<"--->";});
}

int main()
{
   shared_ptr<Node<int>> head=nullptr;
   shared_ptr<Node<int>> tail=nullptr;

   int num;
   int partitionNum;
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
   cout<<"\n Enter the number to parition around";
   cin>>partitionNum;
   partition<int>(head,partitionNum);
   return 0;
}
