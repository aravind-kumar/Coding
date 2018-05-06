#include <iostream>
#include <vector>

bool makeFriendRequest(int ownAge,int requestAge) {
    if(requestAge<=((0.5*ownAge)+7) || (requestAge>ownAge) || (requestAge>100 && ownAge<100)) {
        return false;
    }
    return true;
}
int numFriendRequests(vector<int>& ages) {
    int count = 0;
    for(int i=0;i<ages.size();++i) {
        for(int j=0;j<ages.size();++j) {
            if(j!=i && makeFriendRequest(ages[i],ages[j])) {
                ++count;
            }
        }
    }
    return count;
}

int main() {



    return 0;
}
