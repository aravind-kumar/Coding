#include <iostream>
#include <vector>

vector<int> countBits(int num) {
        vector<int> result(num);
        result.push_back(0);
        for(int i=1;i<=num;++i)
            result[i]=result[(i&(i-1))]+1;
    
    return result;
    }

int main()
{
   int num;
   cout<<"\n Enter the end range ";
   cin>>num;
   for(auto&& nums : countBits(num))
       cout<<nums<<" "<<"\t";

    return 0;
}
