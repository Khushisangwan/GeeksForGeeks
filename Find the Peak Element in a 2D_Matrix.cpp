#include<bits/stdc++.h>
using namespace std;
class Solution {
    public:
        vector<int> findPeakGrid(vector<vector<int>>& mat) {
                // Get dimensions of the matrix
                int n = mat.size();
                int m = mat[0].size();
                
                // Direction arrays for 4 adjacent cells (up, left, down, right)
                int dr[4] = {-1, 0, 1, 0};
                int dc[4] = {0, -1, 0, 1};
                
                vector<int> ans;
                
                // Iterate through each cell in the matrix
                for(int r = 0; r < n; r++){
                        for(int c = 0; c < m; c++){
                                bool peak = 1;  // Assume current cell is a peak
                                
                                // Check all 4 adjacent cells
                                for(int i = 0; i < 4; i++){
                                        int nr = r + dr[i];
                                        int nc = c + dc[i];
                                        
                                        // Check if neighbor is within bounds
                                        if(nr >= 0 && nr < n && nc >= 0 && nc < m){
                                                // If current cell is smaller than neighbor, it's not a peak
                                                if(mat[r][c] < mat[nr][nc]){
                                                        peak = 0;
                                                        break;
                                                }
                                        }
                                }
                                
                                // If peak found, return its coordinates
                                if(peak){
                                        ans.push_back(r);
                                        ans.push_back(c);
                                        return ans;
                                }
                        }
                }
                
                return ans;
        }
};