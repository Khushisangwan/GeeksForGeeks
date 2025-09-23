#include <bits/stdc++.h>
using namespace std;
// function Template for C++

class Solution {
  public:
    queue<int> reverseQueue(queue<int> &q) {
        // code here.
        stack<int> st;
    
        while(!q.empty())
        {
            st.push(q.front());
            q.pop();
        }
        
        while(!st.empty())
        {
            q.push(st.top());
            st.pop();
        }
        
        return q;
    }
};


