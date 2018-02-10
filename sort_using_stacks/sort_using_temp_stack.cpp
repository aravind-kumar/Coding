#include <iostream>
#include <stack>
#include <vector>

using namespace std;
stack<int> sortUsingStack(const vector<int>& nums) {
    stack<int> tempStack;
    stack<int> sortedStack;
    for(auto&& num : nums) {
        if(sortedStack.empty() || num > sortedStack.top()) {
           sortedStack.push(num); 
        } else {
           while(!sortedStack.empty() && num < sortedStack.top()) {
               int top = sortedStack.top();
               tempStack.push(top);
               sortedStack.pop(); 
           } 
           sortedStack.push(num);
           while(!tempStack.empty()) {
               int top = tempStack.top();
               sortedStack.push(top);
               tempStack.pop(); 
           }   
        }
    }
    return sortedStack;
}

int main() {
  vector<int> inputVector;
  int num;
  cout<<"\n Enter the number of elements";
  cin>>num;
  for(int i=0;i<num;++i) {
      int inputNum;
      cout<<"\n Enter the element "<<i<<":";
      cin>>inputNum;
      inputVector.push_back(inputNum);
  }
  stack<int> ans = sortUsingStack(inputVector);
  while(!ans.empty()) {
      cout<<ans.top()<<"--->";
      ans.pop();
  }
  return 0;
}

