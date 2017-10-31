#include <iostream>
#include <functional>
#include <vector>

using namespace std;

void tempFn(function<void (int)> f1)
{
   for(int i=0;i<10;++i)
      f1(i);
}

int main()
{
   vector<int> inputVector;
   auto addToVector = [&inputVector] (int num) { inputVector.push_back(num);};
   tempFn(addToVector);
   for_each(inputVector.begin(),inputVector.end(),[](int num) { cout<<"\n"<<num;});
   return 0;
}
