#include <iostream>

using namespace std;

// Find the number of bits needed to convert from num1 to num2
// We do an xor of num1 and num2 and find the number of bits set.
// We do an xor of num1 and num2 because we to find the number of bits which are different from num1 and num2
// We use xor because if the bits are the same the bit is set to 0 and if different then its set to 1 
// Hence we use xor to find the differnt bits and then we count the bits.

int numOfBitsToConvert(int num1,int num2) {

    int count = 0;
    for(int i=num1^num2; i!=0 ; i=(i&(i-1))) {
        ++count;
    }
    return count;
}

int main() {

    int num1,num2;

    cin>>num1>>num2;

    cout<<"\n The number of bits needed to convert num1->num2"<<numOfBitsToConvert(num1,num2);

    return 0;
}
