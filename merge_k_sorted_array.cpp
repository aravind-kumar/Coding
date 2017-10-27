#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <assert.h>
#include <math.h>

using namespace std;

class Heap
{
   private: 
     vector<int> heapArray;
   public:
     Heap() {}
     Heap(int num)
     {
       heapArray.resize(num);
     }

     Heap(vector<int> givenInput): heapArray(givenInput)
     {
        make_heap(givenInput.begin(),givenInput.end());
     }
     
     void insert(int num)
     {
       heapArray.push_back(num);
       push_heap(heapArray.begin(),heapArray.end());
     }
     
     int top() const
     {
         return heapArray.front();
     }
 
     int size() const
     {
       return heapArray.size();
     }
     
     void pop()
     {
         pop_heap(heapArray.begin(),heapArray.end());
         heapArray.pop_back();
     }  

     void updateKey(int num,int newValue)
     {
         auto pos = find(heapArray.begin(),heapArray.end(),num);
         replace(pos,heapArray.end(),num,newValue);
         make_heap(pos,heapArray.end());
     }
      
     void print()
     {
        for_each(heapArray.begin(),
       		 heapArray.end(),
 	         [](int num) { cout<<"\n" <<num;});
     } 
};

int main()
{
   int k;
   vector<vector<int>> givenInput;
   Heap h; 
   vector<int> output;

   cout<<"\n Enter the number of arrays";
   cin>>k;
   for(int i=0;i<k;++i)
   { 
       int inputSize;
       vector<int> inputArray;
       cout<<"\n Enter the size of the array";
       cin>>inputSize;
       cout<<"\n Enter each every element";
       for(int j=0;j<inputSize;++j)
       {
          int input;
          cin>>input;
          inputArray.push_back(input);
       }
       givenInput.push_back(inputArray);
   }
   
   for_each(givenInput.begin(),givenInput.end(),
            [&h](vector<int> input)
            {
              for_each(input.begin(),input.end(),
                       [&h](int num)
                       {
                          h.insert(num);
                       });
            });

   while(h.size())
   {
      output.push_back(h.top());
      cout<<"\n"<<h.top();
      h.pop(); 
   }
   cout<<is_sorted(output.begin(),output.end());
}
