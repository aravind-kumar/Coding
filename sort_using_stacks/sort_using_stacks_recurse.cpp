#include <iostream>
#include <stack>

using namespace std;

void insertIntoStack(int element,stack<int>& ans) {
   if(ans.empty() || element > ans.top()) {
       ans.push(element);
   } else {
       int top = ans.top();
       ans.pop();
       insertIntoStack(element,ans);
       ans.push(top);
   }
}

void sortStackRecur(stack<int>& inputStack) {
   if(!inputStack.empty()) {
        int top = inputStack.top();
        inputStack.pop();
        sortStackRecur(inputStack);
        insertIntoStack(top,inputStack);
   }

}



int main() {
   stack<int> inputStack;
   int num;
   cout<<"\n Enter the number of elements";
   cin>>num;
   for(int i=0;i<num;++i) {
      int givenNum;
      cout<<"\n Enter the element"<<i<<":";
      cin>>givenNum;
      inputStack.push(givenNum);
   }
   sortStackRecur(inputStack);
   while(!inputStack.empty()) {
       cout<<inputStack.top()<<"-->";
       inputStack.pop();
   }
   return 0;
}

