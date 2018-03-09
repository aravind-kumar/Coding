#include <iostream>
#include <string>

using namespace std;

int substr(string input1,string input2) {
    int m = input1.length(),n=input2.length();
    if(n==0) return 0;
    for(int i=0;i<=m-n;++i) {
        int j=0;
        for(;j<n;++j) {
            if(input1[i+j] != input2[j])
               break; 
        }    
        if(j==n) return i;
    }
    return -1; 
}

int main() {

    string input1,input2;
    cin>>input1>>input2;
    cout<<"\n The first index of input2 in input1 is "<<substr(input1,input2);
    return 0;
}
