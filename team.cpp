#include <iostream>
using namespace std;

int main() {
    int n;
    cin>>n;
    int ans = 0;
    for(int i=0;i<n;++i) {
        int count = 0;
        int num;
        for(int j=0;j<3;++j) {
            cin>>num;
            count+=num;
        }
        if(count>=2) ++ans;
    }
    cout<<ans;
    
    return 0;
}
