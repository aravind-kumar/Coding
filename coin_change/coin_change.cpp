#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


unsigned int minCoins(vector<unsigned int>& coins,unsigned int sum)
{
  vector<int> MinSum(INT_MAX,sum);
  MinSum[0]=-1;

  for(int i=1;i<=sum;++i)
    {
      for(int j=0;i<coins.size();++j)
        {
          if(coins[j]<=i && MinSum[i-(coins[j])]+1 < MinSum[i])
            {
              MinSum[i]=MinSum[i-coin[j]]+1;
            }
        }
    }
  return MinSum[MinSum.size()-1];
}

int main()
{
  vector<unsigned int> coins;
  unsigned int num,sum;

  cout<<"\n Enter the number of coins ";
  cin>>num;

  cout<<"\n Enter the coins";
  for(int i=0;i<num;++i)
  {
      unsigned int input;
      cin>>input;
      coins.push_back(input);
  }

  cout<<"\n Enter the required sum";
  cin>>sum;

  cout<<"\n Minimum number of coins required are "<<minCoins(coins,sum);



  return 0;
}
