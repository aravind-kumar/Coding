#include <iostream>
#include <vector>
#include <stack>

using namespace std;

// This is similar to max area in histrogram but in histrogram we were storing the the histrograms in increasing order.
// However in rain water trapping we are storing histrograms in decreasing order
// and whenever we find a histrogram of greater height
// we computer the maximum water that can be collected for the given tower.
// The maximum water that can be collected is given by min(maxLeftHeight,maxRightHeight)) - heightOfCurrentTower.
// This is for towers what are 1 unit apart.
// to compute the width we use the same formula end-start-1 where end is the rightIndex and start is LeftIndex.
// The rightIndex is considered as the currently iterating index since its greater than the top of the stack 
// The tower under consideration is the top of the stack, whoes  top is to be checked for the maximum amount of water that
// can be collected.
// The leftIndex is the next index present on the stack after the currentIndex i.e do one pop get the current tower under 
// consideration
// Perform two pops and get the left Index.
// Once the max water is computed it accumulated into the globalMax.

int trap(vector<int>& height) {
        
        if (height.empty()) return 0;
        
        stack<int> decreasingHeightIndecies;
        int globalMaxWater = 0;
        
        for(int i=0;i<height.size();++i) {           
            
            while(!decreasingHeightIndecies.empty() && 
                 height[i]> height[decreasingHeightIndecies.top()]) {
                
                 int rightIndex = i;
                 int currentIndex = decreasingHeightIndecies.top(); decreasingHeightIndecies.pop();
                 int leftIndex = decreasingHeightIndecies.empty() ? -1 : decreasingHeightIndecies.top();
                 
                 int rightHeight = height[rightIndex];
                 int currentHeight = height[currentIndex];
                 int leftHeight = leftIndex == -1 ? -1 : height[leftIndex];
                
                 int maxWaterOnCurrentTower = min(leftHeight,rightHeight)-currentHeight;
                 int maxWater = maxWaterOnCurrentTower >=0 ? maxWaterOnCurrentTower : 0;
                 int currentMaxWater = maxWater*(rightIndex-leftIndex-1);
                
                 globalMaxWater+=currentMaxWater;
            }
            decreasingHeightIndecies.push(i);
        }
        
        return globalMaxWater;
        
    }
    
    
    int main() {
    
    
    
    return 0;
    }
