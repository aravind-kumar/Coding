#include <iostream>
#include <unordered_set>

using namespace std;

bool isHappy(int n) {
        unordered_set<int> visited;
        int sum = 0; 
        while(sum || n!=1) {
            if(n) {       
                int digit = n%10;
                n=n/10;
                sum+=digit*digit;
            } else {
                if(!visited.count(sum)) {
                    visited.insert(sum);
                    n = sum;
                    sum = 0;
                } else {
                    return false;
                }
            }
        }
        return n==1 || sum==1;
}

int main() {



    return 0;
}
