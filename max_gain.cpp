#include<bits/stdc++.h>

int max_gain(int arr[], int sz)
{
    if(sz == 0) return 0;
    int minTillNow = arr[0];
    int maxGain = INT_MIN;
    for(int i=1;i<sz;++i) {
        minTillNow = min(minTillNow,arr[i]);
        maxGain = max(maxGain,arr[i]-minTillNow);
    }
    return maxGain == INT_MIN ? 0 : maxGain;
    
    
}


// Max gain is to find the maximum gain that one can get such that the lower is on the left and the higher is on the right.
// The difference is the maximum gain .
// We keep tack of the minimum on the left side and the check on every stage if the next element is greater than the maximum.
// If so then we take the diff and find the maximum gain.
