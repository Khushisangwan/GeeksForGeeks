#include <bits/stdc++.h>
using namespace std;

// Problem: Given a list of non-negative integers, arrange them such that they form the largest number possible.
// Approach is to convert each integer to a string, sort the strings based on a custom comparator, and then concatenate them.

// Steps:
// 1. Convert each integer to a string.
// 2. Sort the strings using a custom comparator that compares concatenated results.
// 3. Handle the case where all numbers are zero.
// 4. Concatenate the sorted strings to form the final result.

// Time Complexity: O(n log n) due to sorting, where n is the number of integers in the input array.
// Space Complexity: O(n) for storing the string representations of the integers.


class Solution {
  public:
    static bool comp(string a, string b) {
         return a + b > b + a;
    }

    string findLargest(vector<int> &arr) {
        vector<string> nums;

        // Convert each number to string
        for (int i = 0; i < arr.size(); i++) {
            nums.push_back(to_string(arr[i]));
        }

        // Sort using custom comparator
        sort(nums.begin(), nums.end(), comp);

        // Handle case when all numbers are zero
        if (nums[0] == "0") {
            return "0";
        }

        // Concatenate result
        string ans = "";
        for (int i = 0; i < nums.size(); i++) {
            ans += nums[i];
        }

        return ans;
    }
};