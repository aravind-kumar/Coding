#include <iostream>
#include <vector>

class Solution {
public:
    vector<string> ambiguousCoordinates(string S) {
        
        S=S.substr(1,S.size()-2); // Ignore the first ( and the last )
        int n = S.size();
        vector<string> result;
        for(int i=1;i<n;++i) // We start from 1 because we take substrings starting from 0 i.e i-1 to 1
        {
            string x = S.substr(0,i),y = S.substr(i,n-i);
            vector<string> xcoords = getCoords(x),ycoords = getCoords(y); // Get all permutations of x and y with decimals.
            for(auto&& x : xcoords) { // For each x and y permute amoung themselves. 
                for(auto&& y : ycoords) {
                    string coordinate = "(" + x + "," + y + ")"; // Form a corrdinate
                    result.push_back(coordinate);
                }
            }
        }
        return result;
    }
    
    vector<string> getCoords(string input) { // Permute for decimal points for a given number 
        vector<string> numbers;
        if(isValid(input))
            numbers.push_back(input);
        int n = input.size();
        for(int i=1;i<n;++i) {
            string beforeDecimal = input.substr(0,i),afterDecimal = input.substr(i,n-i);
            string result = beforeDecimal + '.' + afterDecimal;
            if(isValid(result))
                numbers.push_back(result);
        }
        return numbers;
    }
    
    bool isValid(string input) {
        if(input.size()<2) return true; //i.e 0 or 1 size which would only contain numbers and not . and ) or ( hence always true.
        if(input[0]=='0' && input[1] != '.') return false; // After zero the first character must be .
        if(input.find('.') != string::npos && input.back()==0) return false; // if we have a decimal it shouldnt be 3.0 rather 3
        return tarue;
    }
};
