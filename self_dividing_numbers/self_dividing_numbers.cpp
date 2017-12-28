#include <iostream>
#include <vector>

using namespace std;

bool isPerfect(int num)
{
    int input=num;
    while(num)
    {
        int digit = num %10;
        if (!digit || input%digit) 
            return false;
        num=num/10;
        
    }
    return true;
}
    
vector<int> selfDividingNumbers(int left, int right) {
    vector<int> result;
    for(int i=left;i<=right;++i)
    {
        if(isPerfect(i))
            result.push_back(i);
            
    }
    return result;
}

int main()
{
   int start,end;
   cout<<"\n Enter the start num";
   cin>>start;
   cout<<"\n Enter the end num";
   cin>>end;
   for(auto&& num: selfDividingNumbers(start,end))
      cout<<num<<"-->";
   return 0;
}
