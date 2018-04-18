#include <iostream>
#include <string>

bool isVowel(char c) {
  switch (c) {
      case 'a':
      case 'A':
      case 'e':
      case 'E':
      case 'i':
      case 'I':
      case 'o':
      case 'O':
      case 'u':
      case 'U':
          return true;
      default:
          return false;
  }
        return false;
}

string reverseVowels(string s) {
        
   for(int i=0,j=s.length()-1;i<j;) {
       if(isVowel(s[i]) && isVowel(s[j])) {
           swap(s[i],s[j]);
           ++i;
           --j;
       }
       else if(!isVowel(s[i]))
           ++i;
       else if(!isVowel(s[j]))
           --j;
   }
   
   return s;
}

int main() {
   


    return 0;
}
