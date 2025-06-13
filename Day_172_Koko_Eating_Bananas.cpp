#include <bits/stdc++.h>
using namespace std;
// This code finds the minimum eating speed for Koko to finish all bananas in a given time limit.

class Solution {
    // Helper function to check if Koko can eat all bananas at speed 'mid' within 'k' hours
    bool solve(vector<int>& arr, int mid, int k) {
        int cnt = 0;
        for (int i = 0; i < arr.size(); i++) {
            // Add the number of hours needed for the current pile at speed 'mid'
            cnt = cnt + (arr[i] / mid);
            if (arr[i] % mid != 0) {
                cnt = cnt + 1; // Add one more hour if there are remaining bananas
            }
        }
        // Return true if total hours needed is within allowed hours 'k'
        return cnt <= k;
    }

public:
    // Function to find the minimum eating speed so that Koko can finish all bananas in 'k' hours
    int kokoEat(vector<int>& arr, int k) {
        int n = arr.size();
        int maxi = INT_MIN;
        // Find the maximum number of bananas in any pile
        for (int i = 0; i < arr.size(); i++) {
            maxi = max(maxi, arr[i]);
        }

        int left = 1;        // Minimum possible speed
        int right = maxi;    // Maximum possible speed
        int ans = 0;

        // Binary search to find the minimum feasible eating speed
        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (solve(arr, mid, k)) {
                ans = mid;       // Update answer if current speed is feasible
                right = mid - 1; // Try to find a smaller feasible speed
            } else {
                left = mid + 1;  // Increase speed if current is not enough
            }
        }

        return ans; // Return the minimum eating speed found
    }
};