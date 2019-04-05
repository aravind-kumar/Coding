#include <iostream>
#include <string>

using namespace std;

int main() {
int n;
string input;

cin>>n;
int a=0,d=0;
cin>>input;
for(int i=0;i<input.size();++i)
if(input[i] == 'A') ++a;
else ++d;

if(a>d) cout<<"\n Anton";
else if (d>a) cout<<"\n Danik";
else cout<<"\n Friendship";

return 0;
}
