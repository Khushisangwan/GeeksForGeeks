#include <bits/stdc++.h>
using namespace std;
class Solution {
    public:
        // Function to find maximum area of rectangle in histogram
        int getMaxArea(vector<int> &arr) {
                int n = arr.size();
                stack<int> st; // Stack to store indices
                int ans = 0;
                
                // Iterate through all bars including one extra iteration for remaining stack elements
                for(int i = 0; i <= n; i++){
                        // Process stack when current bar is smaller than stack top or we've reached end
                        while(!st.empty() and (i == n or arr[i] < arr[st.top()])){
                                int idx = st.top(); // Index of the bar being processed
                                st.pop();
                        
                                // Find left and right boundaries for current bar
                                int l_idx = (!st.empty()) ? st.top() : -1; // Left boundary
                                int r_idx = i; // Right boundary
                                
                                // Calculate area with current bar as the smallest bar
                                ans = max(ans, arr[idx] * (r_idx - l_idx - 1));
                        }
                        st.push(i); // Push current index to stack
                }
                
                return ans;
        }
        
        // Function to find maximum area of rectangle in binary matrix
        int maxArea(vector<vector<int>> &mat) {
                int n = mat.size();
                int m = mat[0].size();
                int ans = 0;
                
                // Process each row
                for(int i = 0; i < n; i++){
                        // For each column in current row
                        for(int j = 0; j < m; j++){
                                // If current cell is 1 and not in first row, add height from previous row
                                if(i - 1 >= 0 and mat[i][j] == 1){
                                        mat[i][j] += mat[i-1][j];
                                }
                        }
                        // Find maximum rectangle area in current histogram (row)
                        ans = max(ans, getMaxArea(mat[i]));
                }
                
                return ans;
        }
};