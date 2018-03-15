#include <iostream>

using namespace std;

//We are given two number m,n and asked to merge the bits from [i,j] of M onto N.
// We first clear the bits on N from postion [i,j] we do this by creating a mask
// Once we have created the mask we shift m and append them.
int merge(int m,int n,int i,int j) {

  int ones = ~0;
  int left = ones<<j+1; // j+1 because we want to include j
  int right = (1<<i)-1; // i-1 because we want to include i into the range of cleared bits.
  int mask = left | right;
  int cleardN = n & mask;
  int shiftedM = m<<i;
  return cleardN | shiftedM;

}

int main() {

  int n,m,i,j;
  cin>>n>>m;
  cin>>i>>j;
  cout<<"\n The merged number is "<<merge(m,n,i,j);
  return 0;
}
