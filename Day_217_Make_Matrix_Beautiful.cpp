#include<bits/stdc++.h>
using namespace std;
// Problem Statement: Make the matrix beautiful by balancing row and column sums
// Approach: Calculate the maximum row and column sums, then compute the minimum operations needed
// Time Complexity: O(n^2), where n is the number of rows/columns in the matrix.
// Space Complexity: O(1), no extra space used apart from variables for calculations.
// Note: The solution assumes that the input matrix is square (n x n).
class Solution {
  public:
    int balanceSums(vector<vector<int>>& mat) {
        // code here
         int n=mat.size();
        
        int rowMax=0, colMax=0, sum=0;
        
        for(int i=0; i<n; i++){
            int rowSum=0, colSum=0;
            for(int j=0; j<n; j++){
                sum+=mat[i][j];
                rowSum+=mat[i][j];
                colSum+=mat[j][i];
            }
            rowMax=max(rowMax, rowSum);
            colMax=max(colMax, colSum);
        }
        
        return (rowMax>=colMax)?((n*rowMax)-(sum)):((n*colMax)-(sum));
    
    }
};