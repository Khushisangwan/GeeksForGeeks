#include <bits/stdc++.h>
using namespace std;
class Solution {
    public:
        // Pair type: {current_time, {time_increment, chef_index}}
        using p = pair<int,pair<int,int>>;
        
        int minTime(vector<int>& ranks, int n) {
                // Min heap to track chefs by their current completion time
                priority_queue<p,vector<p>,greater<p>> pq;
                int m = ranks.size(); // number of chefs
                
                // Initialize heap with each chef's rank and initial time increment
                for(int i=0;i<m;i++){
                        pq.push({ranks[i],{2*ranks[i],i}});
                }
                
                int ans = 0;
                // Process n orders
                while(n--){
                        // Get chef with minimum current completion time
                        p temp = pq.top();
                        pq.pop();
                        
                        // Update answer with maximum time seen so far
                        ans=max(ans,temp.first);
                        
                        // Push chef back with updated completion time
                        pq.push({temp.first+temp.second.first,{temp.second.first+ranks[temp.second.second],temp.second.second}});
                }
                return ans;
        }
};