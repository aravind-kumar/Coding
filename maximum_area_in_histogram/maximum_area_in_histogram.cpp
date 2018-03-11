#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int maxAreaInHistogram(vector<int> heights) {
    heights.push_back(0);
    stack<int> increasingHeightIndecies;
    int maxArea = 0;

    for(int i=0;i<heights.size();++i) {
      while(!increasingHeightIndecies.empty() && 
             heights[i] < heights[increasingHeightIndecies.top()]){ // We cant store top as a seperate variable beacause top changes inside te while loop and the top is dynamic keeping it the top as a common variable would have a stale variable
             int height = heights[maxHeightIndex]; increasingHeightIndecies.pop();
             int widht = maxHeightIndex - i - 1;
             int area = widht * height;
             maxArea = max(maxArea,area);
      }
      increasingHeightIndecies.push(i); 
    }
    return maxArea;
}

int main() {
    vector<int> heights = {}; 
    cout<<"\n The maximum area is "<<maxAreaInHistogram(heights);
    return 0;
}
