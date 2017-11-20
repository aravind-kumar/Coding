#include "BST.h"

int main()
{
    BST tree; 
    auto printFunction = [] (Node* node) { cout<<"\n The number is "<<node->num;};

    tree.insert(8);
    tree.insert(3);
    tree.insert(10);
    tree.insert(14);
    tree.insert(13);
    tree.insert(1);
    tree.insert(6);
    tree.insert(4);
    tree.insert(7);
 
    tree.insert(2);
    tree.insert(3);
    tree.insert(1);

    tree.deleteNode(7);
    cout<<"\n Search result for 7 is "<<tree.search(7); 
    tree.deleteNode(8);
    cout<<"\n Search result for 8 is "<<tree.search(8); 
    tree.InorderTraversal(printFunction);
}
