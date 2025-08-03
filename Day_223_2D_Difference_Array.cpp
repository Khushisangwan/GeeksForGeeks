#include<bits/stdc++.h>
using namespace std;
// Problem Statement: Implement a 2D difference array to apply range updates efficiently on a matrix
// Approach: Use a 2D difference array to handle range updates in constant time
// Steps:
// 1. Initialize a difference array of size (n+1)x(m+1) to handle the matrix of size nxm.
// 2. For each operation, update the difference array at the corners of the specified submatrix.
// 3. After processing all operations, compute the prefix sums for both rows and columns to get the final values.
// 4. Update the original matrix with the computed values from the difference array.
// 5. Return the updated matrix.
class Solution {
  public:
    vector<vector<int>> applyDiff2D(vector<vector<int>>& mat,
                                    vector<vector<int>>& opr) {
        // code here
          
        int n = mat.size();
        int m = mat[0].size();
        
        int size = n*m;
        vector<vector<int>>diff(n+1, vector<int>(m+1,0));
        
        for(auto& it: opr)
        {
            int val = it[0];
            int r1 = it[1];
            int c1 = it[2];
            int r2 = it[3];
            int c2 = it[4];
            
            
           
           diff[r1][c1] += val;
           diff[r1][c2+1] -= val;
           
           
           diff[r2+1][c1] -= val;
           diff[r2+1][c2+1] += val;
           
           
        }
        
        // Row Sum 
        for(int r = 0 ; r < n ; r++)
        {
            for(int c= 1 ; c < m ; c++)
            {
                diff[r][c] += diff[r][c-1];
            }
        }
        
        // col Sum
        for(int c = 0 ; c < m ; c++)
        {
            for(int r = 1 ; r < n ; r++)
            {
                diff[r][c] += diff[r-1][c];
            }
        }
        
        for(int r = 0 ; r < n ; r++)
        {
            for(int c = 0 ; c < m ; c++)
            {
                mat[r][c] += diff[r][c];
            }
        }
        
        return mat;
    }
};