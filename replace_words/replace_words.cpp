#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>

using namespace std;

class Solution {
public:
    struct Trie {
        vector<Trie*> children;
        bool isWord;
        Trie() {
            for(int i=0;i<26;++i) {
                children.push_back(nullptr);
            }
            isWord = false;
        }
        
    void insert(string word) {
        
        Trie *current = this;

        for(char character : word) {
            if(current->children[character-'a'] == nullptr) {
                current->children[character-'a'] = new Trie();
            }
            current = current->children[character-'a'];
        }
        current->isWord = true;
    }
    
    /** Returns if the word is in the trie. */
    string search(string word) {
        
        Trie *current = this;
        string rootWord = "";
        for(char character : word) {

            
            if(current->isWord) {
                return rootWord;
            }
            rootWord.push_back(character);
            
            if(current->children[character-'a'] == nullptr) {
                return "";
            }
            
            current = current->children[character-'a'];   
        }
        return current->isWord ? rootWord : "";        
    }
};
    
    /** Inserts a word into the trie. */
          
    string replaceWords(vector<string>& dict, string sentence) {
        Trie *root = new Trie();
        for(string word : dict) {
            root->insert(word);
        }
        
        string output = "";
        string word;
        istringstream words(sentence);
        
        while(words>>word) {
            string rootWord = root->search(word);
            output += rootWord != "" ? rootWord : word;
            output += " ";
        }
        output.pop_back();
        return output;
    
        
    }
};
int main() {



    return 0;
}
