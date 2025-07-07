#include <bits/stdc++.h>
using namespace std;

// Problem: Next Greater Element in Circular Array
// Approach: Use a stack to keep track of indices and find the next greater element in a circular manner.

// Steps:
// 1. Traverse the array twice to handle the circular nature.
// 2. Use a stack to store indices of elements.
// 3. For each element, pop from the stack until the current element is greater than the element at the index stored in the stack.
// 4. If the stack is not empty, the top of the stack will be the next greater element for the popped index.
// 5. If the stack is empty, it means there is no greater element, so we assign -1.
// 6. Return the result array containing the next greater elements.

// Time Complexity: O(n)
// Space Complexity: O(n)

class Solution {
  public:
    vector<int> nextLargerElement(vector<int> &arr) {
        int n = arr.size();
        stack<int> st;
        vector<int> ans(n, -1); // Initialize result array with -1

        // Traverse the array twice to simulate circular array
        for (int i = 0; i < n * 2; i++) {
            // While stack is not empty and current element is greater than element at index on top of stack
            while (!st.empty() && arr[st.top()] < arr[i % n]) {
            ans[st.top()] = arr[i % n]; // Update result for index at top of stack
            st.pop(); // Remove the index as its next greater element is found
            }
            // Only push indices from the first pass
            if (i < n)
            st.push(i);
        }
        return ans;         
    }
};