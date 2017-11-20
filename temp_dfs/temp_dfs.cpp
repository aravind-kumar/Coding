#include <iostream>
#include <vector>

using namespace std;

void printCombinations(int start,vector<int>input)
{

   cout<<start<<"--->";
   if(start != input.size())
       for(int i=start;i<input.size();++i) { 
	printCombinations(start+1,input) ;
	cout<<"\n";
	}
}
int main()
{
   int n;
   vector<int> input;
   cin>>n;
   for(int i=0;i<n;++i)
      input.push_back(i);
   printCombinations(0,input); 
}
