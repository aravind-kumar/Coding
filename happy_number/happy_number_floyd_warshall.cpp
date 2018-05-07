#include <iostream>
#include <unordered_map>

using namespace std;

bool isHappy(int n) {
    unordered_map<int,int> cache;
    return isHappyHelper(cache,n);
}

int getSumOfSquare(unordered_map<int,int>& cache,int num) {
    if(cache.find(num)!=cache.end()) {
        return cache[num];
    } else {
        int sum = 0;
        while(num) {
            int digit = num%10;
            num=num/10;
            sum+=digit*digit;
        }
        cache[num] = sum;
        return sum;
    }
}

bool isHappyHelper(unordered_map<int,int> cache,int num) {
    int slow = num,fast = num;
    while(slow!=1 && fast!=1) {
        slow = getSumOfSquare(cache,slow);
        fast = getSumOfSquare(cache,fast);
        fast = getSumOfSquare(cache,fast);
        if(slow!=1 && fast!=1 && slow == fast) {
            return false;
        }
    }
    return true;
}
int main() {


    return 0;
}
