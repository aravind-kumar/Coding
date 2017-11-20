#include <iostream>
#include <vector>

using namespace std;

int GetIndex(vector<int> input,int low,int high)
{
    if(low<=high)
    {
	int mid = low+(high-low)/2;
        if(input[mid] == mid)
        {
           return mid;
        }
        else if(input[mid]<mid)
        {
          return GetIndex(input,mid+1,high);         
        }
        else 
        {
 	   return GetIndex(input,low,mid-1);
        }

    }
    return -1;
}

int main()
{
   vector<int> input;
   int n;
   cout<<"\n Enter the number of inputs";
   cin>>n;
   
   for(int i=0;i<n;++i)
   {
      int givenInput;
      cin>>givenInput;
      input.push_back(givenInput);
   }
   cout<<"\n The ans is "<<GetIndex(input,0,n-1);

    return 0;
}
