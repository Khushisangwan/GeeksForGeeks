#include<bits/stdc++.h>
using namespace std;
// Problem Statement: Set matrix rows and columns to zero if an element is zero
// Approach: Traverse the matrix and mark rows and columns that need to be zeroed.
// Time Complexity: O(n * m), where n is the number of rows and m is
// the number of columns in the matrix.
// Space Complexity: O(n + m) for storing the rows and columns to be zeroed.
// Note: The solution assumes that the input matrix is non-empty.

class Solution {
  public:
    void setMatrixZeroes(vector<vector<int>> &mat) {
        // code here
          int n=mat.size();
        int m=mat[0].size();
        
        vector<vector<int>>original=mat;
        
        for(int row=0;row<n;row++){
            for(int col=0;col<m;col++){
                if(original[row][col]==0){
                    for(int i=0;i<m;i++){
                        mat[row][i]=0;
                    }
                    for(int j=0;j<n;j++){
                        mat[j][col]=0;
                    }
                }
            }
        }
    }
};
