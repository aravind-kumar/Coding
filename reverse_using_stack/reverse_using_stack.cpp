#include <iostream>
#include <stack>

using namespace std;

void reverseStackRecur(stack<int>& input) {
    if(!input.empty()) {
       int num = input.top();
       input.pop();
       reverseStackRecur(input);
       input.push(num);
    }
}

int main() {
   stack<int> inputStack;
   int num;
   cout<<"\n Enter the number of elements to be inserted";
   cin>>num;
   cout<<"\n Enter the elements";
   for(int i=0;i<num;++i) {
       int givenNum;
       cout<<"\n Enter the number "<<i<<":";
       cin>>givenNum;
       inputStack.push(givenNum);
   }
   reverseStackRecur(inputStack);
   while(!inputStack.empty()) {
       cout<<inputStack.top()<<"--->";
       inputStack.pop();
   }
   return 0;
}
