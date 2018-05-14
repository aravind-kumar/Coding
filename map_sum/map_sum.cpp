#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>

using namespace std;

class MapSum {
public:
    /** Initialize your data structure here. */
    unordered_map<char,MapSum*> children;
    int val;
    
    MapSum() {
        val = 0;
    }
    
    void insert(string key, int val) {
        MapSum *current = this;
        for(char character : key) {
            
            if(current->children.find(character) == current->children.end()) {
                current->children[character] = new MapSum();
            } 
            current = current->children[character];
        }
        current->val = val;
        
    }
    
    void sumHelper(MapSum *root,int& total) {
        if(root != nullptr) {
            for(auto keyVal : root->children) {
                total += keyVal.second->val;
                sumHelper(keyVal.second,total);
            }
        }   
    }
    
    int sum(string prefix) {
        MapSum *current = this;
        
        for(char character : prefix) {
            if(current->children.find(character) == current->children.end()) {
                return 0;
            }
            current = current->children[character];  
        }
        int total = current->val;
        sumHelper(current,total);
        return total;
    }
};

/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum obj = new MapSum();
 * obj.insert(key,val);
 * int param_2 = obj.sum(prefix);
 */
int main() {



    return 0;
}
