#include <bits/stdc++.h>
using namespace std;

// Problem: Search in a fully rotated sorted 2D matrix
// Approach: Iterate through each row, sort it, and then check if the target exists in that row.

// Steps:
// 1. Iterate through each row of the matrix.
// 2. Sort the current row.
// 3. Check if the target element exists in the sorted row.
// 4. If found, return true; otherwise, continue to the next row.
// 5. If the target is not found in any row, return false.
// Note: Sorting each row is not the most efficient way to search in a 2D matrix, but it is a straightforward approach

// Time Complexity: O(n * m * log(m)), where n is the number of rows and m is the number of columns.
// Space Complexity: O(1) for the sorting operation in each row.

class Solution {
  public:
    bool searchMatrix(vector<vector<int>> &mat, int x) {
        int n = mat.size();
        int m = mat[0].size();
        bool flag = false;
        
        for(int i=0; i<n; i++){
            sort(mat[i].begin(), mat[i].end());
            
            for(int j = 0; j< m; j++){
                if(mat[i][j] > x)
                    flag = false;
                else if (mat[i][j] == x){
                    flag = true;
                    break;
                }
            }
            
            if(flag)    break;
        }
        return flag;
    }
};
