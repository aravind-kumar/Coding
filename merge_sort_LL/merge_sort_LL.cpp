#include <iostream>
#include <functional>


template<typename T>
struct Node
{
   T data;
   std::shared_ptr<Node> next;
   Node(T data)
   {
     this->data = data;
     next = nullptr;
   }
};

typedef std::shared_ptr<Node<int>> intNodePtr;

template<typename T>
void performAction(std::shared_ptr<Node<T>> head,std::function<void(T)> fn)
{
   while(head!=nullptr)
   {
      fn(head->data);
      head=head->next;
   }
}

template<typename T>
std::shared_ptr<Node<T>> merge(std::shared_ptr<Node<T>> left,std::shared_ptr<Node<T>> right)
{
    std::shared_ptr<Node<T>> newHead=nullptr,tail=nullptr;
    while(left != nullptr && right != nullptr)
    {
      std::shared_ptr<Node<T>> temp;
      if(left->data < right->data)
      {
         temp = left;
         left = left->next; 
      }
      else
      {
          temp = right;
          right = right->next; 
      }
      if(newHead == nullptr)
      {
         newHead = tail = temp;
      }
      else
      {
          tail->next = temp;
          tail = tail->next;  
      }
    }

    while(left != nullptr)
    {
       tail->next = left;
       tail = tail->next;
       left = left->next; 
    }

    while(right != nullptr)
    {
      tail->next = right;
      tail = tail->next;
      right = right->next;
    }
    return newHead;   
}


template<typename T>
std::shared_ptr<Node<T>> mergeSort(std::shared_ptr<Node<T>> head)
{
   if(head==nullptr || head->next == nullptr)
      return nullptr;
   std::shared_ptr<Node<T>> current=head,runner=head,prev=head; 
   while(current != nullptr && current->next != nullptr)
   {
       prev = runner; 
       runner = runner->next;
       current = current->next->next;
   }
   prev->next = nullptr;
   std::shared_ptr<Node<T>> left = mergeSort(head);
   std::shared_ptr<Node<T>> right = mergeSort(runner);
   
   return merge(left,right); 
   
}

int main()
{
   int num;
   intNodePtr head=nullptr,tail=nullptr;
   std::cout<<"\n Enter the number of nodes";
   std::cin>>num;
   std::cout<<"\n Enter the nodes";
   for(int i=0;i<num;++i)
   {
     int input;
     std::cin>>input;
     intNodePtr newNode(new Node<int>(input));
     if(head == nullptr)
     {
         head = tail = newNode;
     }
     else
     {
         tail->next = newNode;
         tail = tail->next;
     }
   }
   performAction<int>(head,[](int data) { std::cout<<data<<"--->\n";});
   return 0;
}
