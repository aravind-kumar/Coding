#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

//This problem is not similar to max area in histogram.
// In max area of histogram intermediates between start and end arent allowed to have heights lower that min(star,end)
// But in this case we can have intermediate shorter than the start and end 
// However the optimization we are performing here is that we are ignoring them since the area of the intermediates in this
// would be lower than the ones left and right 

// Question : In the below code we are ignoring for all those intermediate ones however shouldnt we increment/decrement i and j
// when the intermediate arent lower.
// Wouldn't that cause an indefnite loop ?
// It wouldnt because at any given point we would atleast increment i or decrement j 
// How ?
// we are comparing height[left]/height[right] with minHeight = min(height[left],height[right])
// Hence either height[right] > minHeight or height[left] < minHeight
// Or if both are eqaul then both because of our condition height[left]<= minHeight and height[right]<=minHeight
// Hence at any given point we would increment left of decrement right;
// Thus resulting in continition of the loop even if its an increasing sequence.

int getMaxWaterContainer(vector<int> height) {
    int left=0,right=height.size()-1;
    int maxArea = 0;
    while(left<right) {
      int minHeight = min(height[left],height[right]);
      maxArea = max(maxArea,(right-left) * minHeight);
      while(left<right && height[left] <= minHeight) ++left;
      while(left<right && height[right] <= minHeight) --right;
    }
    return maxArea;

}
int main() {

    vector<int> input;
    return 0;
}
