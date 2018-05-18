#include <iostream>
#include <vector>

using namespace std;

int findBusiestPeriod( const vector<vector<int> >& data )
{
  if(data.size()>1) {
  
    int numOfPpl = 0;
    int maxPpl = INT_MIN;
    int resultTimeStamp;
  
  
  for(int i=0;i<data.size()-1;++i) {
      
    numOfPpl+= data[i][2] ? data[i][1] : -data[i][1];
  
    if(numOfPpl > maxPpl && data[i][0]!=data[i+1][0]) {
      resultTimeStamp = data[i][0];
      maxPpl = numOfPpl;
    }
  }
  
  return resultTimeStamp;
    
  }
  return data.front().front();
  
}
  

int main() {
  return 0;
}

