
#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    // Main function to check if the string is a sum string
    bool isSumString(string s) {
        int n = s.length();

        // Try all possible splits for the first two numbers
        for (int i = 1; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                string s1 = s.substr(0, i);         // First number
                string s2 = s.substr(i, j - i);     // Second number

                // Skip if numbers have leading zeros (except "0" itself)
                if ((s1.length() > 1 && s1[0] == '0') ||
                    (s2.length() > 1 && s2[0] == '0')) continue;

                // Check if the rest of the string follows the sum property
                if (isValid(s1, s2, s.substr(j))) return true;
            }
        }
        return false;
    }

private:
    // Recursive helper to check if the remaining string is a valid sum string
    bool isValid(string num1, string num2, string remaining) {
        if (remaining.empty()) return true; // All parts matched

        string sum = addStrings(num1, num2); // Calculate sum of previous two numbers
        if (remaining.find(sum) != 0) return false; // Next part doesn't match sum

        // Continue checking with next numbers
        return isValid(num2, sum, remaining.substr(sum.length()));
    }

    // Helper to add two numbers represented as strings
    string addStrings(string num1, string num2) {
        string result;
        int carry = 0, i = num1.length() - 1, j = num2.length() - 1;

        // Add digits from right to left
        while (i >= 0 || j >= 0 || carry > 0) {
            int d1 = (i >= 0) ? num1[i--] - '0' : 0;
            int d2 = (j >= 0) ? num2[j--] - '0' : 0;
            int sum = d1 + d2 + carry;
            result.push_back((sum % 10) + '0'); // Store current digit
            carry = sum / 10;                   // Update carry
        }
        reverse(result.begin(), result.end());  // Reverse to get correct order
        return result;
    }
};
