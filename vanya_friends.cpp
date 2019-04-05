#include <iostream>

using namespace std;

int main() {
int n,h;
int minWidth = 0;
cin>>n>>h;
while(n>0) {
int num;
cin>>num;
if(num <= h)  minWidth++;
else minWidth+=2;
--n;
}

cout<<minWidth;

}
