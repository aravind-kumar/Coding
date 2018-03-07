#include <iostream>
#include <unordered_set>

using namespace std;

struct node {
    int data;
    node *next;
    node(int data) {
       this->data = data;
       next = nullptr;
    }
};

void removeDuplicates(node* head) {

   unordered_set<int> set;
   set.insert(head->data);
   while(head->next != nullptr) {
       if(set.find(head->next->data) == set.end()) {
           set.insert(head->next->data); 
           head = head->next;
       } else {
          auto next = head->next;
          head->next = head->next->next; 
          delete next;
       }
   }
}

int main() {




}
