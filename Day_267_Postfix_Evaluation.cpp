#include <bits/stdc++.h>
using namespace std;
class Solution {
    public:
        // Function to evaluate a postfix expression
        int evaluatePostfix(vector<string>& arr) {
                // Stack to store operands
                stack<long long> st;

                // Process each token in the postfix expression
                for (string &s : arr) {
                        if (isOperator(s)) {
                                // Pop two operands (order matters: second popped is first operand)
                                long long b = st.top(); st.pop();  // Second operand
                                long long a = st.top(); st.pop();  // First operand
                                
                                // Apply the operator and push result back to stack
                                long long res = applyOp(a, b, s);
                                st.push(res);
                        } else {
                                // Convert string number to integer and push to stack
                                st.push(stoll(s));
                        }
                }
                // The final result is the only element left in stack
                return (int)st.top();
        }

    private:
        // Check if a string is an operator
        bool isOperator(const string &s) {
                return (s == "+" || s == "-" || s == "*" || s == "/" || s == "^");
        }

        // Apply the given operator to two operands
        long long applyOp(long long a, long long b, const string &op) {
                if (op == "+") return a + b;
                if (op == "-") return a - b;
                if (op == "*") return a * b;
                if (op == "/") {
                        // Handle floor division correctly for negative numbers
                        long long res = a / b;
                        // If signs differ and there's a remainder, subtract 1 for floor division
                        if ((a ^ b) < 0 && a % b != 0) res--;
                        return res;
                }
                if (op == "^") return pow(a, b);  // Power operation
                return 0;  // Default case (should not reach here)
        }
};