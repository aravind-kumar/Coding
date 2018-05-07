#include <iostream>

using namespace std;

// Add till you get a single digit number

int addDigits(int num) {
        int sum = 0;
        while(sum/10 != 0 || num) {
            if(num) {
                int digit = num%10;
                num = num / 10;
                sum+=digit;
            } else {
                num = sum;
                sum = 0;
            }
        }
        return sum;
        
    }

int main() {


    return 0;
}
