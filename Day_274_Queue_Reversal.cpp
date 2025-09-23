#include <bits/stdc++.h>
using namespace std;
// function Template for C++

class Solution {
    public:
        queue<int> reverseQueue(queue<int> &q) {
                // Create a stack to store queue elements
                stack<int> st;
        
                // Transfer all elements from queue to stack
                // This reverses the order due to LIFO nature of stack
                while(!q.empty())
                {
                        st.push(q.front());  // Push front element of queue to stack
                        q.pop();             // Remove front element from queue
                }
                
                // Transfer all elements back from stack to queue
                // Elements are now in reverse order
                while(!st.empty())
                {
                        q.push(st.top());    // Push top element of stack to queue
                        st.pop();            // Remove top element from stack
                }
                
                return q;  // Return the reversed queue
        }
};
