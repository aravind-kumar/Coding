#include <iostream>
#include <unordered_set>
#include <string>
#include <numeric>

using namespace std;

int numOfJewelsInStones(string j,string s) {

    unordered_set<char> jewels;
    for(auto character : j) {
        jewels.insert(character); 
    }
    auto maximizer = [jewels](int acc,char input) { return jewels.count(input) ? acc+1 : acc;};
    return accumulate(s.begin(),s.end(),0,maximizer);

}

int main() {

    string j,s;
    cin>>j>>s;
    cout<<"The number of jewels in stones are"<<numOfJewelsInStones(j,s);

}
