// Question : Given an array we are asked to replace every element in the array with the product of numbers in the array except itself.
// This has to be done for all the elements in the array.
// A naive approach would be to multiply all the elements in the array and then divide each number by the cumulative product and assign the value to the array.
// However the catch in the question is that we arent allowed to use division operator.
// So how do we solve it ?
// Instead of division lets look at the problem as a product problem
// The value in a cell should be equal to cumulative product of all the elemets to its left * cumulative product of all the elements to its
// right i.e cell[i] = cumProd(cell[0,i-1]) * cumProd([n,i+1])
// Approach 1 would be to store all the left cumulative product in vector 1 and then cumulative product of right in vector 2 and multiply
// vec1[i] with vec[i] where 0<=i<=n
// ie vec1(left) = cumulative product of the element to the left of i excluding i.
// so what is the value of i=0 since there is no element to the left of 0 and we cannot include the element 0
// It would have a value of 1
// Similarly the value of vec2(right)[n] would be 1
#include <iostream>
#include <vector>

using namespace std;

vector<int> productExceptItself(vector<int>& nums) {

     vector<int> ans(nums.size());
     
     int left = 1;
     ans[0] = 1;
     for(int i=1;i<nums.size();i++) {
        left = left*nums[i-1];
        ans[i] = left; 
     }
     int right=1;
     for(int j=nums.size()-2 ; j>=0 ; --j) {
        right = right*nums[j+1];
        ans[j] = ans[j] * right;
     }
     return ans;
}

int main() {
    vector<int> input = {1,2,3,4};
    input = productExceptItself(input); 
    for_each(input.begin(),input.end(),[](int num) { cout<<num <<" "; });
}
