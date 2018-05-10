#include <iostream>
#include <math.h>

using namespace std;

//Reffer : https://leetcode.com/problems/consecutive-numbers-sum/discuss/129015/5-lines-C++-solution-with-detailed-mathematical-explanation.

//Basically we use the formula for consective sum n*(n-1)/2 upto k terms that is k=2,3,4,5 that is 2 consective numbers,3 consective numbers
//x+(x+1)+(x+2)...k = N (given number)
// kx+k(k-1)/2 = N
// kx = N-(k(k-1)/2)
// x = (N-(k(k-1)/2)/k 
// Hence everytime we have N-(k(k-1)/2) is divisible by k we have a valid x
// We use to find all the valid x's and count them.
// Now till what value of k should one go to ..? 

//since RHS > 0 
// N-(k(k-1)/2)/k > 0 
// .. k< sqrt(2N)

int consecutiveNumbersSum(int N) {
      int count = 1;
       for( int k = 2; k < sqrt( 2 * N ); k++ ) {
           if ( ( N - ( k * ( k - 1 )/2) ) % k == 0) {
               count++;
           }
       }
       return count;
       
}

int main() {


    return 0;
}
