#include <bits/stdc++.h>
using namespace std;

// Problem Statement: Find the last time point where at least k intervals overlap
// Approach: Use a sweep line algorithm with a map to track the start and end of intervals

// Steps:
// 1. Create a map to store the start and end of each interval.
// 2. Iterate through the intervals and update the map with the start and end points.
// 3. Use a variable to keep track of the current number of overlapping intervals.
// 4. Traverse the map to find the last time point where the number of overlapping intervals is at least k.
// 5. Return the last time point found.

// Time Complexity: O(n log n), where n is the number of intervals, due to sorting the events.
// Space Complexity: O(n), for storing the events in the map.

#define ll long long
class Solution {
  public:
    int powerfulInteger(vector<vector<int>>& in, int k) {
        map<ll,ll>mp;
        for(auto it : in){
            mp[it[0]]++;
            mp[it[1]+1]--;
        }
        ll h=0;
        ll ans=-1;
        ll prev=LLONG_MIN;
        bool is=false;
        for(auto it : mp){
            h+=it.second;
            if(is){
                ans=max(prev,it.first-1);
            }
            if(h>=k){
                is=true;
            }
            else{
                is=false;
            }
            prev=it.first;
        }
        return ans;
    }
};
