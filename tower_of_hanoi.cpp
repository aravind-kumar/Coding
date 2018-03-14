#include <iostream>


using namespace std;

// This operation would take 2^n moves to complete.
// we first move n-1 decks from tower 3 to tower 2 assuming we have to move to desk 1 as destination
// once all the n-1 decks have been used to tower 2
// We move the last deck to tower 1
// After moving all the decks to tower 2 and the the largest to tower 3 we move all the intermeidate one to the final one
// using the src node as intemediate 

void towerOfHanio(int num,char src,char dest,char intermediate) { 

  if(n==1) {
    cout<<"Moving node from "<<src <<" dst";  
  } else {
    towerOfHanio(num-1,src,intermediate,dest);
    cout<<"\n Moving "<<num<< " From "<< src<< " dst";
    towerOfHanio(num-1,intermediate,dest,src);
  }
}

int main() {

  int num;
  char src,dest,intermediate;
  cin>>num;
  cin>>src>>dest>>intermediate;
  
  towerOfHanio(num,src,dest,intermediate);
  return 0;
}
