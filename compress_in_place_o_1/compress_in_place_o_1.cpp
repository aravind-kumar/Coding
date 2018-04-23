#include <iostream>
#include <vector>
#include <string>


int compress(vector<char>& chars) {
    
        int wall=-1;
        int i=0,j;
        while(i<chars.size()) {
            int count = 1;
            j=i+1;
            while(j<chars.size() && chars[i] == chars[j]) {
                ++j;
                ++count;
            }
            ++wall;
            chars[wall]=chars[i]; // Assign the character event if it has only one count;
            if(count>1) {      // Now check if it has count if so assign count;
                string countString = to_string(count);
                for(int k=0;k<countString.size();++k) {
                    ++wall;
                    chars[wall] = countString[k];  
                }  
            }
            i=j;
        }
        if(wall!=-1) 
            chars.erase(chars.begin()+wall+1,chars.end());
        return chars.size();
}

int main() {



    return 0;
}
