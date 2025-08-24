#include <bits/stdc++.h>
using namespace std;

// Problem: Minimize the Heights I
// Approach: Use recursion with memoization to find all distinct sums that can be formed using the elements of the array

// Steps:
// 1. Define a recursive function solve that explores all combinations of including or excluding each element
// 2. Use a set to store distinct sums and a 2D vector for memoization to avoid recomputation
// 3. Call the solve function starting from index 0 and sum 0
// 4. Convert the set of distinct sums to a vector and return it
// 5. Ensure the sums are sorted by using a set
// 6. Return the vector of distinct sums

// Time Complexity: O(n * sum), where n is the number of elements and sum is the total sum of elements.
// Space Complexity: O(n * sum) for the memoization table and O(k) for the set of distinct sums, where k is the number of distinct sums.


class Solution {
  public:
    int getMinDiff(vector<int> &arr, int k) {
        int n = arr.size();
        sort(arr.begin(), arr.end());
        int res = arr[n - 1] - arr[0];
        
        for(int i = 1; i < arr.size(); i++){
            int minH = min(arr[0] + k, arr[i] - k);
            int maxH = max(arr[n - 1] - k, arr[i - 1] + k);
            res = min( res, maxH - minH);
        }
        return res;
    }
};