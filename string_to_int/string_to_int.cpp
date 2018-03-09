#include <iostream>
#include <math.h>
#include <string>

using namespace std;

unsigned long int strToInt(string input) {

    unsigned long int ans=0,exp = 0;
    
    for(int i = input.length()-1;i>=0;--i) {
        ans+=((input[i]-'0')*(pow(10,exp)));
        exp++;
    }
    return ans;
}
 
int main() {

    string input;
    cout<<"Enter the input string";
    cin>>input;
    cout<<"\n The converted output is "<<strToInt(input);
 
    return 0;
}
