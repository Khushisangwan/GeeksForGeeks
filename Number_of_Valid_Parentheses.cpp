#include <bits/stdc++.h>
using namespace std;
class Solution {
    public:
        // Function to find the number of valid parentheses combinations
        int findWays(int n) {
                // If n is odd, valid parentheses cannot be formed
                if(n%2 ==1) return 0;
                // Start recursive helper with position 0, 0 open and 0 close parentheses
                return helper(0, 0, 0, n);
        }
        
        // Recursive helper function to count valid parentheses
        // pos: current position, l: count of open parentheses, r: count of close parentheses, n: total length
        int helper(int pos, int l, int r, int n) {
                // Base case: reached end of string
                if(n == pos) {
                        // Valid only if we have equal open and close parentheses
                        if(l > r) return 1;
                        else return 0;
                }
                
                // Pruning: cannot add more open parentheses than n/2
                if(l > n/2) return 0;
                
                // Pruning: cannot have more close parentheses than open ones
                if(r > l) return 0;
                
                // Recursively try adding open parenthesis or close parenthesis
                return helper(pos+1, l+1, r, n) + helper(pos+1, l, r+1, n);
        }
};