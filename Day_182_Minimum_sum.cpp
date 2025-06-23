#include<bits/stdc++.h>
using namespace std;
// Problem: Minimum Sum of Two Numbers Formed by Array Digits
// Approach to find the minimum sum of two numbers formed by the digits of an array.
// Steps:
// 1. Sort the array to arrange digits in ascending order.
// 2. Pair the largest digits with the smallest digits to minimize the sum.
// 3. Use a carry to handle cases where the sum exceeds 9.
// 4. Construct the result string by iterating through the sorted array in reverse order.

class Solution {
    public:
        // Function to find the minimum sum of two numbers formed by array digits
        string minSum(vector<int> &arr) {
                string ans; // To store the result as a string
                int carry = 0; // To handle carry over during addition
                sort(arr.begin(), arr.end()); // Sort the digits in ascending order

                // Traverse the array from the end, pairing digits to form two numbers
                for (int i = arr.size() - 1; i >= 0; i -= 2) {
                        // Sum the current digit, the previous digit (if exists), and carry
                        int sum = (arr[i] + (i - 1 >= 0 ? arr[i - 1] : 0) + carry);
                        ans.push_back('0' + (sum % 10)); // Store the unit digit
                        carry = (sum / 10); // Update carry
                }

                // If any carry remains, add it to the result
                if (carry) ans.push_back('0' + carry);

                // Remove leading zeros from the result
                while (ans.size() > 1 && ans.back() == '0') ans.pop_back();

                // Reverse the string to get the correct order
                reverse(ans.begin(), ans.end());

                return ans; // Return the minimum sum as a string
        }
};