#include <iostream>
#include <vector>
#include <utility>
#include <unordered_map>

using namespace std;

// In the previous solution we were manually checking if the back and front of a given card were to be of that of a given number then its 
// not possible for it a be good number.
// In this solution we elimiate those numbers whose back and front are same because they cannot be part of the solution.
// And then we iterate through the solution set to find the min number.
// We do not check if the back is same because if it were to be same then it would be a part of impossible number
// If the front matches then we are sure that the back woulnt match because we have it already stored such numbers as a part of impossible
// numbers.
// Hence if its not a part of impossible number but if the front matches the given number then we can be sure that the back wouldnt match 
// and flipping it would solve the problem.
// Hence we do not double check as done in the previous problem
    
int flipgame(vector<int>& fronts, vector<int>& backs) {
    unordered_set<int> impossibleNumber;
    for(int i=0;i<fronts.size();++i) {
        if(fronts[i] == backs[i]) {
            impossibleNumber.insert(fronts[i]);
        }
    }
    
    int res = INT_MAX;
    for(int num : fronts) {
        if(!impossibleNumber.count(num)) {
            res = min(res,num);
        }
    }
    
    for(int num : backs) {
        if(!impossibleNumber.count(num)) {
            res = min(res,num);
        }
    }
    
    return res==INT_MAX ? 0 : res;
}


int main() {




}
