#include <iosteam>
#include <vector>
#include <algorithms>
#include <utility>

using namespace std;
int main()
{
   int num;
   vector<int> inputVector;
   cout<<"\n Enter the number of inputs";
   cin>>num;
   cout<<"\n Enter the number of elements";
   for(int i=0;i<num;++i)
   {
     int givenElement;
     cout<<"\n Enter the elements";
     cin>>givenElement;
     inputVector.push_back(giveElement);
   }
   
   return 0;
}
