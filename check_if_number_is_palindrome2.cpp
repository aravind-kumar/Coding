#include <iostream>

using namespace std;

class Solution {
public:
    
    bool isPalindrome(int x) {
        if(x<0 || x%10 == 0 && x!=0) return false; // If x is negative then its a not a palindrome and if the last digit is 0 then the only possiblity of the number being a palindrome is when x==0 otherwise its not a zero.
        
        int reversedNumber = 0;
        //Since we are dividing the given number by 10 and the multiplying the reversed number by 10 everytime.
        // We should have reached half the number of digits when the given number < reversedNumber.
        while(x>reversedNumber) {
            reversedNumber = reversedNumber*10 + x%10;
            x=x/10;
        }
        
        return x==reversedNumber || x==reversedNumber/10; // We divide the given number by 10 when the digits are of odd length we remove the last digit inorder to check its a palindrome.
        
        
        
    }
};

int main() {


  return 0;
}
