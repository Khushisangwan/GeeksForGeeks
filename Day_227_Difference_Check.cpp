#include <bits/stdc++.h>
using namespace std;

// Problem Statement: Find the minimum time difference between pairs of time strings
// Approach: Convert time strings to seconds, sort them, and find the minimum difference

// Steps:   
// 1. Convert each time string to total seconds from the start of the day.
// 2. Sort the array of seconds.
// 3. Calculate the minimum difference between consecutive times.
// 4. Also consider the difference between the last and first time to account for the circular nature of time.
// 5. Return the minimum of these differences.

// Time Complexity: O(n log n) due to sorting, where n is the number of time strings    
// Space Complexity: O(n) for storing seconds in an array

class Solution {
  public:
    int minDifference(vector<string> &arr) {
        int n=arr.size();
        vector<int> seconds(n);
        for(int i=0;i<n;i++) {
            int hours=(arr[i][0]-'0')*10+(arr[i][1]-'0');
            int minutes=(arr[i][3]-'0')*10+(arr[i][4]-'0');
            int secs=(arr[i][6]-'0')*10+(arr[i][7]-'0');
            seconds[i]=(hours*3600)+(minutes*60)+secs;
        }
        sort(seconds.begin(),seconds.end());
        int minDiff=INT_MAX;
        for(int i=0;i<n-1;i++) {
            minDiff=min(minDiff,seconds[i+1]-seconds[i]);
        }
        return min(minDiff,86400-seconds[n-1]+seconds[0]);
    }
};