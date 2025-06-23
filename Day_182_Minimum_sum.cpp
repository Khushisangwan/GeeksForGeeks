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
    string minSum(vector<int> &arr) {
        string ans;
        int carry = 0;
        sort(arr.begin(), arr.end());
        for (int i = arr.size() - 1; i >= 0; i -= 2) {
            int sum = (arr[i] + (i - 1 >= 0 ? arr[i - 1] : 0) + carry);
            ans.push_back('0' + (sum % 10));
            carry = (sum / 10);
        }
        if (carry) ans.push_back('0' + carry);
        while (ans.size() > 1 && ans.back() == '0') ans.pop_back();
        reverse(ans.begin(), ans.end());
        return ans;
    }
};