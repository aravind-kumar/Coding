#include <iostream>
#include <vector>

using namespace std;


class Trie {
    
public:
    /** Initialize your data structure here. */
    bool isWord;
    vector<Trie*> children;
    
    Trie() {
        isWord = false;
        for(int i=0;i<26;++i) {
            children.push_back(nullptr);
        }
    }
    
    /** Inserts a word into the trie. */
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
    bool search(string word) {
        
        Trie *current = this;
        for(char character : word) {
            if(current->children[character-'a'] == nullptr) {
                return false;
            }
            current = current->children[character-'a'];   
        }
        return current->isWord;
        
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        
        Trie *current = this;
        for(char character : prefix) {
            if(current->children[character-'a'] == nullptr) {
                return false;
            }
            current = current->children[character-'a'];   
        }
        return true;   
        
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie obj = new Trie();
 * obj.insert(word);
 * bool param_2 = obj.search(word);
 * bool param_3 = obj.startsWith(prefix);
 */
int main() {



    return 0;
}
