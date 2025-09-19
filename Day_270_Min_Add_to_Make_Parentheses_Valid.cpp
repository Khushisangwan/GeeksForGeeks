#include <bits/stdc++.h>
using namespace std;
class Solution {
    public:
        int minParentheses(string& s) {
                // Initialize counters for unmatched opening and closing parentheses
                int open = 0;   // Count of unmatched opening parentheses '('
                int close = 0;  // Count of unmatched closing parentheses ')'
                
                // Iterate through each character in the string
                for(char cha : s){
                        if(cha=='('){
                                // Found opening parenthesis - increment open counter
                                open++;
                        } else if(cha ==')'){
                                // Found closing parenthesis
                                
                                // Check if there's an unmatched opening parenthesis to pair with
                                if(open>0){
                                        // Match with previous opening parenthesis
                                        open--;
                                } else{
                                        // No opening parenthesis to match - increment close counter
                                        close++;
                                }
                        }
                }
                
                // Return total unmatched parentheses (both opening and closing)
                return open+close;
        }
};