#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Given that a person can take either 1 step at a time or two steps at time or 3 steps at a time
// We have to find the number of ways to reach step N.
// This problem is similar to Fibonnachi. 
// In fibonnachi we only depend on the previous two number but in this case we depend upon the previous 3 numbers.
// This could further be optmized in space by only using the 3 variables since at given point in time the input only
// depends upon 3 of its pervious input's

int getNumOfWays(int num,vector<int> cache) {
    cache[0] = 1;
    for(int i=1;i<=num;++i) {
        
        int n_1 = i-1 >=0 ? nums[i-1] : 0;
        int n_2 = i-2 >=0 ? nums[i-2] : 0;
        int n_3 = i-3 >=0 ? nums[i-3] : 0;
        
        nums[i] = n_1 + n_2 + n_3;
    
    }
    
    return cache.back();
}
int main() {
  
    int n;
    cin>>n;
    vector<int> cache(n,0);
    cout<<"\n The number of ways are" <<getNumOfWays(n,cache);
    
    return 0;
}
