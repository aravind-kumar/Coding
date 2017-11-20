#include <iostream>
#include <unordered_map>
#include <string>
#include <algorithm>
#include <utility>

using namespace std;

bool isDeclareStatement(unordered_map<string,int> variableMap,string inputString)
{
    string delimiter = "=";
    string variable = inputString.substr(0,s.find(delimiter));
    string operands = inputString.substr(s.find(delimiter),s.length());
    for(auto&& chars : operands)
    { 
       if(variableMap.find(chars) != variableMap.end())
       {
           return true;  
       }
    }
    return false; 
}

void AddToMap(unordered_map<string,int>& variableMap,string inputString)
{
    string delimiter = "=";
    string variable = inputString.substr(0,s.find(delimiter));
    string operand = inputString.substr(s.find(delimiter),s.length());
    if(isNum(operands))
    {
       variableMap[variable] = operand;
    }
}

int EvaluateExpression(unordered_map<string,int> variableMap,string inputString)
{
    string delimiter = "=";
    string variable = inputString.substr(0,s.find(delimiter));
    string operands = inputString.substr(s.find(delimiter),s.length());
    bool isAdd = false;
    bool isSub = false;
    bool isMul = false;
    bool isDiv = false;    

    std::size_t found = inputString.find("*");
    if (found!=std::string::npos) isMul = true;

    std::size_t found = inputString.find("+");
    if (found!=std::string::npos) isAdd = true;
    
    std::size_t found = inputString.find("-");
    if (found!=std::string::npos) isSub = true;

    std::size_t found = inputString.find("/");
    if (found!=std::string::npos) isDiv = true;
    
    int sum=0;
    int prod=1;

    for(auto&& element : inputString)
    { 
       if(variableMap.find(element) != null)
       {
          if(isAdd)
          {
             sum+=variableMap[element];
          }
          if(isMul)
          {
             prod*=variableMap[element];
          }
          
       }
    }
}

int main()
{
   int n;
   vector<string> input;
   unordered_map<string,int> variableMap;
   cout<<"\n Enter the number of lines";
   cin>>n;
   for(int i=0;i<n;++i)
   {
     string inputString;
     cin>>>inputString;
     if(isDeclareStatement(variableMap,inputString))
     {
        AddToMap(variableMap,inputString); 
     }
     else
     input.push_back(inputString);
   }
   cout<<EvaluateExpression(variableMap,input);
   return 0;
}
