#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    string removeKdig(string s, int k) {
        string st;  // works as stack

        // Iterate through each character in the string
        for (char c : s) {
            // Remove larger digits from stack if we can still remove digits (k > 0)
            // This ensures we get the lexicographically smallest result
            while (!st.empty() && k > 0 && st.back() > c) {
                st.pop_back();
                k--;
            }
            st.push_back(c);
        }

        // If still need to remove digits, remove from the end
        while (k > 0 && !st.empty()) {
            st.pop_back();
            k--;
        }

        // Remove leading zeros
        int i = 0;
        while (i < st.size() && st[i] == '0') i++;

        // Extract the result substring without leading zeros
        string ans = st.substr(i);

        // Return "0" if result is empty, otherwise return the result
        if (ans.empty()) return "0";
        return ans;
    }
};