include <iostream>

using namespace std;


//Question : We have to swap the even position bits with odd position bits.
//of a given number with minimum number of instructions
// We first create a mask with all odd position of a number being set = 0xaaaaaaaaa
// we And this with the num and and get all the odd positions.
// Now we have all the odd position numbers.
// We have to move them to even position so we do a right shift.

// Similarly we create a mask of all the numbers with even positions being set.
// After we have the even bits of the number being set.
// we and it with the given number and get the even positioned bits and the rest of bits being 0.
// Now we have to even positioned bits which have to moved to odd positions.
// For that we left shift.
// After that we append (or) the numbers to get the final answer

int swapEvenOddBits(int num) {

    return (((num & 0xaaaaaaaa)>>1) | ((num & 0x55555555)<<1));

}

int main() {

    int num;
    cin>>num;
    cout<<swapEvenOddBits(num);
    return 0;
}
