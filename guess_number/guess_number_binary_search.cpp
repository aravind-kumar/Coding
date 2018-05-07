#include <iostream>

using namespace std;

int guessNum = 0;
int guess(int num) {
    return num - guessNum;
}

int guessNumber(int n) {
    int low = 1,high = n;
    while(low<=high) {
        int mid = low + (high-low)/2;
        int result = guess(mid);
        if(!result) {
            return mid;
        } else if(result==1) {
            low = mid+1;
        } else {
            high = mid-1;
        }
    }
    return -1;
    
}

int main() {
    cin>>guessNum;

    return 0;
}
