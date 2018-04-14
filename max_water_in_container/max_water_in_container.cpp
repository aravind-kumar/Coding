#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;

int maxWaterInContainer(vector<int> walls) {
   int left = 0,right=walls.size(); 
   int maxWater = 0;
   while(left<right) {
      int minHeight = min(left,right);
      maxWater=max(maxWater,minHeight*(right-left+1));
      while(left < right && walls[left]<=walls[right]) ++left;
      while(left < right && walls[left]<=walls[right]) --right;

   }
   return maxWater;
}

int main() {


   return 0;
}
