#include <iostream>

template <typename T>
struct Node {
   T data;
   Node *left,*right;
   Node(T data) {
       this.data = data;
       left = right = nullptr;
   }
};

template<typename T>
bool isBSTHelper(Node<T> *root,Node<T> *pre) {
    if(root != nullptr)
    {
        if(!isBSTHelper(root->left,pre))
            return false;
        if(pre != nullptr && pre->data > root->data)
            return false;
        pre = root;           
        return isBSTHelper(root->right,pre); 
    }
    return true;
}

template<typename T>
bool isBST(Node<T> *root) {
   Node<T> *pre = nullptr;
   return isBSTHelper(root,pre); 
}

template<typename T>
Node<T>* newNode(T data){
    return new Node<T>(data);
}

int main() {
    struct Node<int> *root = newNode<int>(3);
    root->left        = newNode<int>(2);
    root->right       = newNode<int>(5);
    root->left->left  = newNode<int>(1);
    root->left->right = newNode<int>(4); 

    return 0;
}
