#include <bits/stdc++.h>
using namespace std;

// Problem: Gold Mine Problem
// Approach: Dynamic Programming

// Steps:
// 1. Define a recursive function to explore all possible paths in the grid.
// 2. Use memoization to store results of subproblems to avoid redundant calculations.
// 3. Iterate through each row in the first column to find the maximum gold that can be collected.
// 4. Return the maximum gold collected.

// Time Complexity: O(n * m) where n is the number of rows and m is the number of columns in the grid.
// Space Complexity: O(n * m) for the memoization table.

class Solution {
    int n , m ; 
    int f(vector<vector<int>> & grid , vector<vector<int>> & dp , int i , int j){
        if(i >= n || j < 0 || j >= m || i < 0){
            return 0 ; 
        }
        if(dp[i][j] != -1) return dp[i][j] ; 
        return dp[i][j] = grid[i][j] + max({f(grid, dp , i+1 , j+1), f(grid , dp , i , j+1) , f(grid , dp , i-1 , j+1)});
    }
    public:
    int maxGold(vector<vector<int>>& mat) {
        n = mat.size() , m = mat[0].size() ; 
        int res = 0 ; 
        vector<vector<int>> dp(n+1, vector<int>(m+1 , -1)) ; 
        for(int i = 0 ; i < n ; i++){
            res = max(res , f(mat ,dp , i , 0)) ; 
        }
        return res; 
    }
};