#include <bits/stdc++.h>
using namespace std;
class Solution {
    public:
        int longestSubarray(vector<int>& arr) {
                // Find longest subarray where length >= maximum element in that subarray
                int n = arr.size();
                int mxLen = 0;
                
                // Stack to store indices for finding next greater element
                stack<int> st;

                // Iterate through array + one extra iteration for final processing
                for(int i = 0; i <= n; i++){
                        // Current element (use INT_MAX for final iteration to process remaining elements)
                        int nge = (i == n ? INT_MAX : arr[i]);
                        
                        // Process all elements in stack that are smaller than current element
                        while(!st.empty() && arr[st.top()] < nge){
                                int curr = arr[st.top()];  // Current element being processed
                                st.pop();
                                
                                // Calculate length of subarray where curr is the maximum
                                // If stack is empty, subarray starts from beginning (length = i)
                                // Otherwise, subarray is between previous element in stack and current position
                                int len = st.empty() ? i : i - st.top() - 1;
                                
                                // Check if subarray length >= maximum element value
                                if(len >= curr) {
                                        mxLen = max(mxLen, len);
                                }
                        }
                        st.push(i);  // Push current index to stack
                }
                
                return mxLen;
        }
};