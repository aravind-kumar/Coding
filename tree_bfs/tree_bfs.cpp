#include <iostream>
#include <queue>

using namespace std;

struct node {

    int data;
    node *left,*right;
    node(int data) {
       this->data = data;
       left = right =nullptr; 
    }

};

void doBfs(node* root,function<void(int)> fn) {

     if (root!= nullptr) {
        queue<node*> bfsQueue;
        bfsQueue.push(root);
        while(!bfsQueue.empty()) {
           auto top = bfsQueue.front();
           bfsQueue.pop();
           fn(top->data);
           if(top->left != nullptr) {
               bfsQueue.push(top->left); 
           }  
           if(top->right != nullptr) {
               bfsQueue.push(top->right); 
           } 
        }
     }
}

int main() {

    node* root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->left->left = new node(4);
    root->left->right = new node(5);
    auto printfn = [](int data) { cout<<data<<" ";};
    doBfs(root,printfn);
}
