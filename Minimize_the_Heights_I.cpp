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
    void solve(int idx, int sum, int n, vector<int>nums, set<int>&ans, vector<vector<bool>>&dp){
        if(idx >= n){
            ans.insert(sum);
            return;
        }
        
        if(dp[idx][sum]) return;
        
        dp[idx][sum] = true;
        
        solve(idx+1 , sum , n , nums , ans , dp);
        solve(idx+1 , sum + nums[idx] , n , nums , ans , dp);
    }
 
    vector<int> DistinctSum(vector<int>nums){
        int n = nums.size();
        int maxSum = accumulate(nums.begin() , nums.end() , 0);
        vector<vector<bool>>dp(n , vector<bool>(maxSum + 1 , false));
        set<int>ans;

        solve(0 , 0 , n , nums , ans , dp);
        return vector<int>(ans.begin() , ans.end());
    }
};