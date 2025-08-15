#include <bits/stdc++.h>
using namespace std;
// Problem: Insert Interval
// Approach: Insert the new interval into the list of intervals and merge any overlapping intervals
// Steps:
// 1. Add the new interval to the list of existing intervals.
// 2. Sort the intervals based on their starting points.
// 3. Iterate through the sorted intervals and merge any overlapping intervals.
// 4. If two intervals overlap, merge them by updating the end of the first interval to the maximum end of both intervals.
// 5. Return the merged list of intervals.

class Solution {
  public:
    vector<vector<int>> insertInterval(vector<vector<int>> &itrl,
                                       vector<int> &nitr) {
        // code here
        itrl.push_back(nitr);
        int n=itrl.size();
        sort(itrl.begin(),itrl.end());
        for(int i=1;i<n;i++){
            auto x=itrl[i-1];
            auto y=itrl[i];
            if(x[1]>=y[0]){
                if(x[1]>=y[1]){
                    itrl[i]=itrl[i-1];
                    itrl[i-1][0]=-1;
                }
                else{
                    itrl[i][0]=itrl[i-1][0];
                    itrl[i-1][0]=-1;
                }
            }
        }
        vector<vector<int>>ans;
        for(auto i:itrl){
            if(i[0]!=-1)ans.push_back(i);
        }
        return ans;
    }
};