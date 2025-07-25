#include<bits/stdc++.h>
using namespace std;
// Problem Statement: Find the maximum sum of a circular subarray.
// Approach: Calculate both the maximum subarray sum and the circular subarray sum.
// Time Complexity: O(n), where n is the size of the array.
// Space Complexity: O(1), no extra space used.

class Solution {
  public:
    // arr: input array
    // Function to find maximum circular subarray sum.
    int circularSubarraySum(vector<int> &arr) {
        int totalSum = 0;
        int currMaxSum = 0, currMinSum = 0;
        int maxSum = arr[0], minSum = arr[0];

        for (int i = 0; i < arr.size(); i++) {

            currMaxSum = max(currMaxSum + arr[i], arr[i]);
            maxSum = max(maxSum, currMaxSum);

            currMinSum = min(currMinSum + arr[i], arr[i]);
            minSum = min(minSum, currMinSum);

            totalSum = totalSum + arr[i];
        }

        int normalSum = maxSum;
        int circularSum = totalSum - minSum;

        if (minSum == totalSum)
            return normalSum;

        return max(normalSum, circularSum);
    }
};