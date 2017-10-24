#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <math.h>
#include <utility>
using namespace std;

class Heap
{
  vector<int> heapArray;

  public:
  int parent(int index)
  {
      return floor((index/2));
  }
  int left(int index)
  {
      return index*2;
  }
  int right(int index)
  {
      return (index*2)+1;
  }

  void Heapify(int startIndex)
  {
     int leftIndex = left(startIndex);
     int rightIndex =  right(startIndex);
     int largestIndex = startIndex;
     if(leftIndex<heapArray.size() && heapArray[leftIndex] > largestIndex)
        largestIndex = leftIndex;
     if(rightIndex<heapArray.size() && heapArray[rightIndex] > heapArray[largestIndex])
        largestIndex = rightIndex;
     if(largestIndex!=startIndex)
     {
       swap(heapArray[largestIndex],heapArray[startIndex]);
       Heapify(largestIndex);
     }
  }
 
  void insert(int num)
  {
      heapArray.push_back(num);
      int i = heapArray.size()-1;
      while(i>=0 && heapArray[i]>heapArray[parent(i)])
      {
         swap(heapArray[i],heapArray[parent(i)]);;
      }
  }

  int top()
  {
      return heapArray[0];
  }

  void extractMax()
  {
     int head = heapArray[0];
     swap(heapArray[0],heapArray.back());
     Heapify(0);
     heapArray.erase(find(heapArray.begin(),heapArray.end(),head));
  }

  void updateKey(int key,int newValue)
  {
     if(key>=0 && key<heapArray.size()-1)
     { 
        int currentValue = heapArray[key];
        int leftValue = heapArray[left(key)];
        int rightValue = heapArray[right(key)];
        heapArray[key] = newValue;
        if(newValue > currentValue)
        {
          Heapify(parent(newValue));
        }
        if(newValue> leftValue || newValue> rightValue)
        {
          Heapify(key);
        }
     }     
  }
  
  void print()
  {
      for_each(heapArray.begin(),heapArray.end(),
               [](int num) { cout<<"\n"<<num;});
  }
};


int main()
{
  Heap h; 
  h.insert(17);
  h.insert(15);
  h.insert(10);
  h.insert(6);
  h.insert(10);
  h.insert(7);
  h.print();
  cout<<"--------------------";
  cout<<"top : "<<h.top();
  h.extractMax();
  h.print();
  return 0;
}
