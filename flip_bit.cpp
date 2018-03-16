//We are given a number and we can at max flip a single bit and we have to find the maximum length of number of 1s
//that could be achieved.
// We use an approach similar to kadanes algorithm
// We maintain a running maxmimim and a current lenght,previous lenght ,
// We need the previous length because incase the we flip one of the bits we have to add the previous sequence and
// current sequence numbers.
// If not then we just have to reset the previous lenght to 0.
// The resetting is done at line 25. we keep incrementing the lenght till its 1 and once we find a 0 we reset it 0 and 
// reassign previous length depeding upon the next bit if its one then its current length otherwise its 0 since we broke a.

#include <iostream>
#include <algorithm>
#include <utility>

using namespace std;

int flipBit(int n) {

    int currentLength = 0,maxLength = 1,previousLength = 0;

    while(n!=0) {
       if(n & 1) {
           ++currentLength;
       } else {
         previousLength = (n&2) == 0 ? 0 : currentLength;
         currentLength = 0;
       }
       maxLength=max(maxLength,currentLength+previousLength+1);
       n>>=1;
   }

   return maxLength;

}

int main() {

    int n;
    cin>>n;
    cout<<"\n The ans is "<<flipBit(n);
    return 0;
}
