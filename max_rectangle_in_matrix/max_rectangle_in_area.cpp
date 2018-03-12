#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <utility>

using namespace std;

int maxAreaInHistogram(vector<int> heights) {
     
    heights.push_back(0);
    int maxArea = 0;
    stack<int> increasingHeightIndex;
    for(int i=0;i<heights.size();++i) {
        while(!increasingHeightIndex.empty() &&
               heights[i] < heights[increasingHeightIndex.top()]) {
             int height = heights[increasingHeightIndex.top()]; increasingHeightIndex.pop();
             int start = !increasingHeightIndex.empty() ? increasingHeightIndex.top() : -1;
             int width = i-start -1;
             int area = height * width;
             maxArea = max(maxArea,area); 
        } 
        increasingHeightIndex.push(i);
    }
    return maxArea;
}

int maxAreaInRectangle(vector<vector<char>> input) {

    if(input.empty()) return 0;
    vector<int> height(input.front().size(),0);
    int maxRectangleArea = 0;
    for(auto row : input) {
       for(int i=0;i<row.size();++i) {
           height[i] = row[i] == '1' ? height[i]+1 : 0; 
       } 
       int maxArea = maxAreaInHistogram(height);
       maxRectangleArea = max(maxRectangleArea,maxArea);
    }
    return maxRectangleArea;
}

int main() {
  vector<vector<int>> matrix;


  return 0;
}
