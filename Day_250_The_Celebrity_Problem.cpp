#include<bits/stdc++.h>
using namespace std;
class Solution {
    public:
        int celebrity(vector<vector<int>>& mat) {
                // Get the size of the matrix (number of people)
                int n = mat.size();
                
                // Initialize in-degree array to track each person's celebrity score
                // Celebrity should have in-degree of (n-1) and out-degree of 0
                vector<int> in(n, 0);
                
                // Iterate through the adjacency matrix
                for(int i = 0; i < n; i++) {
                        for(int j = 0; j < n; j++) {
                                
                                // If person i knows person j (mat[i][j] == 1)
                                if(mat[i][j]) {
                                        in[j]++;  // Increment j's in-degree (someone knows j)
                                        in[i]--;  // Decrement i's score (i knows someone, so can't be celebrity)
                                }
                        }
                }
                
                // Find the person with in-degree of (n-1)
                // This means everyone else knows them and they know nobody
                for(int i = 0; i < n; i++) {
                        if(in[i] == n - 1) return i;  // Return the celebrity's index
                }
                
                // Return -1 if no celebrity exists
                return -1;
        }
};