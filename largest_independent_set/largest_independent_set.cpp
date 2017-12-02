#include <iostream>
#include <unordered_set>

typdef shared_ptr<Node> nodePtr;
typedef unordered_set<nodePtr,int> sizeMap;

template <typename T>
struct Node
{
   T data;
   Node* next;
};
 
template <typename T>
int getMaxIndependentSetSize(shared_ptr<Node<T>> root,sizeMap& givenMap)
{
    if(root==nullptr)
       return 0;
    auto it = givenMap.find(root);
    if(it != givenMap.end()) {
       return it->second;
    }
    auto sizeWithoutIncludingRoot = getMaxIndependentSetSize(root->left,givenMap) +
    				    getMaxIndependentSetSize(root->right,givenMap);
    auto sizeIncludingRoot = 1;
    if(root->left)
    sizeIncludingRoot += getMaxIndependetSetSize(root->left->left,givenMap) +
			 getMaxIndependentSetSize(root->left->right,givenMap) +
    if(root->right)
    sizeIncludingRoot += getMaxIndependentSetSize(root->right->left,givenMap) +
			 getMaxIndependentSetSize(root->right->right,givenMap);

    int maxSize = max(sizeWithoutIncludingRoot,sizeIncludingRoot);
    givenMap.insert(make_pair<nodePtr,int>(root,maxSize));
    return maxSize;
}


int main()
{

   return 0;
}
