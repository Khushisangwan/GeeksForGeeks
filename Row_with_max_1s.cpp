#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    // Find the row with maximum number of 1s in a binary matrix
    // Time Complexity: O(n + m), Space Complexity: O(1)
    int rowWithMax1s(vector<vector<int>> &arr) {
        int n = arr.size();      // number of rows
        int m = arr[0].size();   // number of columns
        int row = 0;             // start from first row
        int ans = -1;            // stores row index with max 1s (-1 if no 1s found)
        int idx = m - 1;         // start from last column (rightmost)

        // Two-pointer approach: start from top-right corner
        while (row < n && idx >= 0) {
            if (arr[row][idx] == 1) {
                // Found a 1, this row has at least one 1
                ans = row;
                // Move left to find the first 1 in this row
                idx--;
            } else {
                // Current element is 0, move to next row
                row++;
            }
        }
        return ans;
    }
};