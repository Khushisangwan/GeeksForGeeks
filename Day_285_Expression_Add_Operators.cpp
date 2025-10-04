#include <bits/stdc++.h>
using namespace std;
class Solution {
    public:
        vector<string> findExpr(string &s, int target) {
                // Main function to find all expressions that evaluate to target
                vector<string> ans;
                solve(0, s, target, "", ans, 0, 0);
                return ans;
        }
        
private:
        void solve(int index, string &num, int target, string curr, vector<string>& ans, long prev, long res) {
                // Base case: if we've processed all characters
                if(index == num.length()) {
                        // Check if current result equals target
                        if(res == target) {
                                ans.push_back(curr);
                        }
                        return;
                }
                
                string st = "";           // Current number being formed
                long currRes = 0;         // Numeric value of current number
                
                // Try all possible numbers starting from current index
                for(int i = index; i < num.length(); i++) {
                        // Skip numbers with leading zeros (except single digit 0)
                        if(i > index && num[index] == '0') break;
                        
                        // Build current number character by character
                        st += num[i];
                        currRes = currRes * 10 + (num[i] - '0');
                        
                        if(index == 0) {
                                // First number in expression - no operator needed
                                solve(i + 1, num, target, st, ans, currRes, currRes);
                        } else {
                                // Try addition: add current number to result
                                solve(i + 1, num, target, curr + "+" + st, ans, currRes, res + currRes);
                                
                                // Try subtraction: subtract current number from result
                                solve(i + 1, num, target, curr + "-" + st, ans, -currRes, res - currRes);
                                
                                // Try multiplication: multiply previous number with current number
                                // Need to undo previous operation and apply multiplication
                                solve(i + 1, num, target, curr + "*" + st, ans, prev * currRes, res - prev + (prev * currRes));
                        }
                }
        }
};