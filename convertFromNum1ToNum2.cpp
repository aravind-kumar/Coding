#include <iostream>

using namespace std;

// Find the number of bits needed to convert from num1 to num2
// We do an xor of num1 and num2 and find the number of bits set.

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
