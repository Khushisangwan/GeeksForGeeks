#include <bits/stdc++.h>
using namespace std;

// Problem: Longest subarray with at most two distinct integers
// Approach: Sliding Window Technique

// Steps:
// 1. Use a sliding window to maintain the current subarray.
// 2. Use a map to count the frequency of elements in the current window.
// 3. Expand the window by moving the right pointer.
// 4. If the number of distinct elements exceeds two, shrink the window from the left
// 5. Keep track of the maximum length of the valid subarray found.
// 6. Return the maximum length found.

// Time Complexity: O(n), where n is the size of the input array
// Space Complexity: O(1) for the map, since we only store at most two distinct integers

class Solution {
  public:
     int totalElements(vector<int> &arr) {
        int ans = 0; // To store the maximum length found
        int i = 0, j = 0; // Window pointers
        map<int, int> mp; // Map to store frequency of elements in the current window

        while (j < arr.size()) {
            mp[arr[j]]++; // Add current element to the map (expand window)
            int c = mp.size(); // Number of distinct elements in the window

            // If more than 2 distinct elements, shrink window from the left
            while (c > 2) {
            mp[arr[i]]--; // Decrease frequency of leftmost element
            if (mp[arr[i]] == 0) {
                mp.erase(arr[i]); // Remove element if its frequency is zero
                c--; // Decrement count of distinct elements
            }
            i++; // Move left pointer to the right
            }

            ans = max(ans, j - i + 1); // Update maximum length if current window is valid
            j++; // Move right pointer to the right
        }
        return ans; // Return the maximum length found
    }
};