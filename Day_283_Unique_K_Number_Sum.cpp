#include <bits/stdc++.h>
using namespace std;
class Solution {
    public:
        // Recursive helper function to find combinations
        // ans: stores all valid combinations
        // a: current combination being built
        // n: remaining sum needed
        // k: number of elements still needed in combination
        // j: starting number for next iteration (ensures no duplicates)
        void get(vector<vector<int>> & ans, vector<int> a, int n, int k, int j){
                // Base case: if we have k numbers and sum equals n
                if (k == a.size() && n == 0) {
                        ans.push_back(a);
                        return;
                }
                else {
                        // Try numbers from j to 9
                        for (int i = j; i <= 9; i++) {
                                a.push_back(i);              // Add current number
                                get(ans, a, n-i, k, i+1);    // Recurse with reduced sum and next starting number
                                a.pop_back();                // Backtrack - remove current number
                        }
                }
        }
        
        
        // Main function to find all combinations of k unique numbers that sum to n
        vector<vector<int>> combinationSum(int n, int k) {
                vector<vector<int>> ans;
                get(ans, {}, n, k, 1);  // Start recursion with empty combination and starting number 1
                return ans;
        }
};