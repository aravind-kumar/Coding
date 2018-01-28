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

template<typename T>
void findKthtoLast(shared_ptr<Node<T>> head,int k)
{
    shared_ptr<Node<T>> current=head,runner=head;
    while(k--) current = current->next;
    while(current!=nullptr)
    {
       runner = runner->next;
       current = current->next;
    }
    cout<<"\n The kth node from the last is "<<runner->data;
}

int main()
{
   shared_ptr<Node<int>> head=nullptr;
   shared_ptr<Node<int>> tail=nullptr;

   int num;
   int k;
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
   
   cout<<"\n Which number from the kth should be found " ;
   cin>>k;
   findKthtoLast<int>(head,k);
   return 0;
}
