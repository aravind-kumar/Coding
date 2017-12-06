#include <iostream>
#include <stack>


vector<int> dailyTemperatures(vector<int>& temperatures) {
        
        stack<pair<int,int>> tempStack;
        vector<int> result(temperatures.size());
        if(!temperatures.empty())
        {
            tempStack.emplace(make_pair(temperatures.front(),0));
            
            for(int i=1;i<temperatures.size();++i)
            {
                auto stackTop = tempStack.top();
                if(temperatures[i] < stackTop.first)
                    tempStack.emplace(make_pair(temperatures.at(i),i));
                else
                {
                    while(!tempStack.empty() && 
                          temperatures[i] > (tempStack.top()).first)
                    {
                      auto srcIndex = (tempStack.top()).second;
                      auto dstIndex= i;
                      result[srcIndex]=dstIndex-srcIndex;
                      tempStack.pop();
                    }
                    tempStack.emplace(make_pair(temperatures.at(i),i));
                }
            }
            
        }
        return result;
        
    }

int main()
{


   return 0;
}
