#include <iostream>
#include <vector>
#include <set>
#include <map>

using namespace std;

typedef pair<int,int> coord;

vector<coord> getSkyline(vector<vector<int>> buildings) {

    multimap<int,int> coordinates; // To keep the coordinates sorted,we can also use vector + sort

    for(auto&& building : buildings) {
       coordinates.emplace(building[0],building[2]);
       coordinates.emplace(building[1],-building[2]);
    }
   
    multiset<int> heightQueue; // Priority Queue for maintaining height, we could also priorit queue but it doesnt allow delete.
    map<int,int> ans; //To store the processed corrdiates we can also use vector but we use hashmap to handle edges cases where the x coincides with y of another point and so on..watch tushar video to find the edge cases.

    for(auto coordinate : coordinates) {
    	if(coordinate.second > 0) {
            heightQueue.emplace(coordinate.second); 
        } else {
            heightQueue.erase(heightQueue.find(-coordinate.second)); // We use find here because we only want to delete a single instance of the height when encountered a negative height and not all the ones.
        }
        int maxHeight = *(heightQueue.rbegin());
        ans[coordinate.first] = maxHeight;
    }
    
    vector<coord> finalAns;
    auto cmp = [](coord a,coord b) { return a.second ==  b.second;};
    unique_copy(ans.begin(),ans.end(),back_inserter(finalAns),cmp);
    return finalAns; 
     


}

int main() {

  

}
