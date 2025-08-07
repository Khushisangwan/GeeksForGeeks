#include <bits/stdc++.h>
using namespace std;

// Problem Statement: Convert a Roman numeral string to an integer
// Approach: Use a map to store the values of Roman numerals and iterate through the string

// Steps:
// 1. Create a map to store the values of Roman numeral characters. 
// 2. Initialize a variable to hold the result.
// 3. Iterate through the string, checking the value of the current character and the next character.
// 4. If the current character's value is less than the next character's value, subtract it from the result.
// 5. Otherwise, add it to the result.
// 6. Return the final result.

// Time Complexity: O(n), where n is the length of the input string
// Space Complexity: O(1) for the map, as it contains a fixed number of characters


class Solution {
  public:
    int romanToDecimal(string &s) {
        unordered_map<char, int> value = {
            {'I', 1},
            {'V', 5},
            {'X', 10},
            {'L', 50},
            {'C', 100},
            {'D', 500},
            {'M', 1000}
        };

        int ans = 0;
            
        for (int i = 0; i < s.size(); ++i) {
            int curr = value[s[i]];
            int next = 0;
            if(i<s.size()-1){
                next = value[s[i+1]];
            }
    
            if (curr < next)
                ans -= curr;
            else
                ans += curr;
        }
    
        return ans;
    }
};