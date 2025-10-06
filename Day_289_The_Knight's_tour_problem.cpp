#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<int>> ans;  // Stores the final solution path
    bool flag = false;        // Flag to stop recursion once solution is found
    int arr[8] = {-1, 1, -2, -2, -1, 1, 2, 2};   // Row movements for knight's 8 possible moves
    int brr[8] = {-2, -2, -1, 1, 2, 2, -1, 1};   // Column movements for knight's 8 possible moves
    int n;  // Board size
    
    void solve(int i, int j, vector<vector<int>>& vis, int sum) {
        // If solution already found, return immediately
        if (flag) {
            return;
        }
        
        // If all squares are visited, we found a solution
        if (sum == n * n) {
            ans = vis;
            flag = true;
            return;
        }
        
        // Try all 8 possible knight moves
        for (int x = 0; x < 8; x++) {
            int p = i + arr[x];  // New row position
            int q = j + brr[x];  // New column position
            
            // Check if new position is valid and unvisited
            if (p >= 0 && q >= 0 && p < n && q < n && vis[p][q] == -1) {
                vis[p][q] = sum;           // Mark current move number
                solve(p, q, vis, sum + 1); // Recursively explore from new position
                vis[p][q] = -1;           // Backtrack: unmark the position
            }
        }
    }
    
    vector<vector<int>> knightTour(int m) {
        // Initialize board size
        n = m;
        
        // Create visited matrix initialized with -1 (unvisited)
        vector<vector<int>> vis(n, vector<int>(n, -1));
        
        // Start from position (0,0) with move number 0
        vis[0][0] = 0;
        
        // Begin the knight's tour from (0,0) with next move as 1
        solve(0, 0, vis, 1);
        
        return ans;
    }
};