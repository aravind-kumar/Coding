#include <iostream>
#include <vector>
#include <utility>

using namespace std;

void flip(vector<int>& input,int k) {
    for(int i=0;i<=k/2;++i) {
        swap(input[i],input[k-i]); 
    }
}

int getMaxIndex(vector<int> input,int till) {
    int maxNum = INT_MIN;
    int index = -1;
    for(int i=0;i<input.size() && i<=till;++i) {
        if(input[i]>maxNum) {
            maxNum = input[i];
            index = i;
        }
    }
    return index;
}

void pancakeSort(vector<int>& input) {

    for(int i=0,j=input.size()-1;i<input.size() && j>=0;++i,--j) {
        int maxIndex = getMaxIndex(input,j);
        flip(input,maxIndex);
        flip(input,j);
    }
}

int main() {
   vector<int> input={2,4,5,3,1};
   pancakeSort(input);
   for(int num:input) {
       cout<<num<<endl;
   }
   return 0;
}
