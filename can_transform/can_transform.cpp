#include <iostream>
#include <string>

using namespace std;
class Solution {
public:
    bool canTransform(string start, string end) {
        int pos1=0,pos2=0;
        
        while(pos1<start.length() && pos2<end.length()) {     
            while(pos1<start.length() && start[pos1] == 'X') pos1++;
            while(pos2<end.length() & end[pos2] == 'X') pos2++;
            
            if(pos1==start.length() && pos2==end.length()) 
                return true;
            if(pos1==start.length() || pos2==end.length())
                return false;
            if(start[pos1] != end[pos2])
                return false;
            if(start[pos1] == 'L' && pos2>pos1)
                return false;
            if(start[pos1] == 'R' && pos2<pos1)
                return false;
            
            ++pos1;
            ++pos2;
        }
        return true;
        
    }
};


int main()
{
   Solution s;
   string s1,s2;
   cout<<"\n Enter the source string";
   cin>>s1;
   cout<<"\n Enter the destination string";
   cin>>s2;
   cout<<"\n Can the source string be transformed into destination string "<<s.canTransform(s1,s2);
   return 0;
}
