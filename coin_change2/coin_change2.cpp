#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

unsigned int numOfCoins(vector<unsigned int>& coins,unsigned int sum)
{
  vector<int> MinSum(INT_MAX,sum);
  

}

int main()
{
  vector<unsigned int> coins;
  unsigned int sum,numOfCoins;

  cout<<"\n Enter the number of conis";
  cin>>numOfCoins;

  cout<<"\n Enter coins";
  for(int i=0;i<numOfCoins;++i)
    {
      unsigned int input;
      cin>>input;
      coins.push_back(input);
    }

  cout<<"\n Enter the sum";
  cin>>sum;

  cout<<"\n The minimum number of coins"<<numOfCoins(coins,sum);
  return 0;
}
