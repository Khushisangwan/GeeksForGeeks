#include<bits/stdc++.h>
using namespace std;
class Solution {
    public:
        // Main function to generate all permutations of an array
        vector<vector<int>> permuteDist(vector<int>& arr) {
                vector<vector<int>> ans; 
                backtrack(arr, 0, ans); 
                return ans;
        }
        
        // Helper function that generates permutations using backtracking
        void backtrack(vector<int>& arr, int idx, vector<vector<int>>& ans) { 
                // Base case: if we've reached the end of array, store this permutation
                if (idx == arr.size()) { 
                        ans.push_back(arr); 
                        return; 
                } 
                // Try swapping each element from idx to end
                for (int i = idx; i < arr.size(); i++) { 
                        swap(arr[idx], arr[i]);  // Swap current element with element at i
                        backtrack(arr, idx + 1, ans);  // Recurse for next position
                        swap(arr[idx], arr[i]);  // Backtrack: undo the swap
                } 
        }
};