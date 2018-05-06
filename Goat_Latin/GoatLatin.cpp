#include <iostream>
#include <string>
#include <istringstream>

using namespace std;

bool isVowel(char input) {
        switch(input) {
            case 'A':
            case 'E':
            case 'I':
            case 'O':
            case 'U':
            case 'a':
            case 'e':
            case 'i':
            case 'o':
            case 'u':
                return true;
        }
        return false;
    }
    
string toGoatLatin(string S) {
        istringstream inputStream(S);
        string output="",word="";
        int count = 1;
        while(inputStream>>word) {
            if(!isVowel(word[0])) {
                char start = word[0];
                word.erase(word.begin());
                word.push_back(start);
            }
            word=word+"ma";
            for(int i=0;i<count;++i) {
                word.push_back('a');
            }
            output+=word;
            output.push_back(' ');
            word="";
            ++count;
        }
        output.pop_back();       
        return output;
        
}


int main() {




    return 0;
}
