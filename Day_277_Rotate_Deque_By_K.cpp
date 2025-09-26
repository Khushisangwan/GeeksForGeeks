#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    // Function to rotate a deque by k positions
    // type = 1: rotate right (clockwise), type = 0: rotate left (counter-clockwise)
    static void rotateDeque(deque<int>& dq, int type, int k) {
        if (type == 1) {
            // Rotate right (last to front)
            // Move elements from back to front k times
            while (k--) {
                dq.push_front(dq.back()); // Take last element and add to front
                dq.pop_back();             // Remove the last element
            }
        } else {
            // Rotate left (first to back)
            // Move elements from front to back k times
            while (k--) {
                dq.push_back(dq.front()); // Take first element and add to back
                dq.pop_front();            // Remove the first element
            }
        }
    }
};