#include <bits/stdc++.h>
using namespace std;
// This code removes adjacent balls of the same color and radius from a vector and returns the number of remaining balls.

class Solution {
    public:
        int findLength(vector<int> &color, vector<int> &radius) {
                // Vector to act as a stack to store the balls
                vector<pair<int,int>> v;
                
                // Iterate through all balls
                for(int i = 0; i < color.size(); i++) {
                        // If the stack is not empty and the top ball has the same color and radius as the current ball
                        if(!v.empty() && v.back().first == color[i] && v.back().second == radius[i]) {
                                // Remove the top ball (adjacent same ball found)
                                v.pop_back();
                        } else {
                                // Otherwise, push the current ball onto the stack
                                v.push_back({color[i], radius[i]});
                        }
                }
                // Return the number of balls remaining after all removals
                return v.size();
        }
};