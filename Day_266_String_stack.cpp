#include <bits/stdc++.h>
using namespace std;
class Solution {
    public:
        bool stringStack(string &pat, string &tar) {
                // code here
                int n = pat.size();  // Length of pattern string
                int m = tar.size();  // Length of target string
                
                int i = n-1;  // Pointer for pattern string (starting from end)
                int j = m-1;  // Pointer for target string (starting from end)
                int count = 0;  // Counter to track operations
                
                // Traverse both strings from end to beginning
                while (i >= 0 && j >= 0) {
                        
                        // If characters match
                        if (pat[i] == tar[j]) {
                                if (count % 2 == 0) {  // Even count means we can match directly
                                        j--;  // Move target pointer backward
                                        count = 0;  // Reset count
                                        i--;  // Move pattern pointer backward
                                }
                                else {  // Odd count means we need to pop from stack
                                        i--;  // Move pattern pointer backward
                                        count++;  // Increment count
                                }
                        }
                        else {  // Characters don't match
                                i--;  // Move pattern pointer backward (skip this character)
                                count++;  // Increment count (simulate pushing to stack)
                        }
                }
                
                // Return true if all target characters are matched
                if (j < 0) return true;
                else return false;
        }
};
