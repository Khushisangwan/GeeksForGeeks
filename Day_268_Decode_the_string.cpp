#include <bits/stdc++.h>
using namespace std;
class Solution {
    public:
        string decodedString(string &s) {
                // Stack to store characters and brackets
                stack<string> num;
                string res = "";
                int c = 0;
                
                // Process each character in the input string
                for(char ch : s) {
                        if(ch == ']') {
                                // Found closing bracket, start decoding
                                string str = "";
                                
                                // Extract the string inside brackets
                                while(num.top() != "[") {
                                        str = num.top() + str;
                                        num.pop();
                                }
                                num.pop(); // Remove the opening bracket '['
                                
                                res = "";
                                res = str + res;
                                str = res;
                                
                                // Extract the number before the brackets
                                string dig = "";
                                while(!num.empty() && isdigit(num.top()[0])) {
                                        dig = num.top() + dig;
                                        num.pop();
                                }
                                
                                // Convert digit string to number
                                long long n = stoll(dig);
                                
                                // Repeat the string n times
                                while(--n > 0) {
                                        res += str;
                                }
                                
                                // Push the decoded result back to stack
                                num.push(res);
                        } else {
                                // Push current character to stack
                                num.push(string() + ch);
                        }
                }
                
                // Remove the last element and build final result
                num.pop();
                while(!num.empty()) {
                        res = num.top() + res;
                        num.pop();
                }
                
                return res;
        }
};