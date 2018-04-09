#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>
 
using namespace std;

int uniqueMorseRepresentations(vector<string>& words) {
        vector<string> morseCodes = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
        
        unordered_set<string> morseAlpha;
        
        int uniqueCount = 0;
        for(string word : words) {
            string morse="";
            for(char character : word) {
                morse+=morseCodes[character-'a'];
            }
            if(morseAlpha.find(morse) == morseAlpha.end()) {
                uniqueCount++;
                morseAlpha.insert(morse);
            }
        }
        
        return uniqueCount;
    }


int main() {



   return 0;
}
