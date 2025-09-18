#include <bits/stdc++.h>
using namespace std;
class Solution {
    public:
        vector<int> nextGreater(vector<int> &arr) {
                // Get the size of input array
                int n = arr.size();
                
                // Initialize result vector with -1 (default for no greater element)
                vector<int> ans(n, -1);
                
                // Stack to store elements in decreasing order
                stack<int> st;
                
                // Traverse the array twice (2*n) to handle circular nature
                // Start from the end to process elements in reverse order
                for(int i = 2*n - 1; i >= 0; i--) {
                        // Remove elements from stack that are smaller or equal to current element
                        while(!st.empty() && st.top() <= arr[i % n]) {
                                st.pop();
                        }
                        
                        // If stack is not empty and we're in first pass (i < n),
                        // the top element is the next greater element
                        if(!st.empty() && i < n) {
                                ans[i] = st.top();
                        }
                        
                        // Push current element to stack for future comparisons
                        st.push(arr[i % n]);
                }
                
                return ans;
        }
};