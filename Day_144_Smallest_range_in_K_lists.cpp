#include<bits/stdc++.h>
using namespace std;
class Solution {
  public:
    vector<int> findSmallestRange(vector<vector<int>>& arr) {
        // code here
         map<int,int>poin;
        int maxi=0;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>minH;
        int minRange=INT_MAX;
        for(int i=0;i<arr.size();i++){
            poin[i]=0;
            minH.push({arr[i][0],i});
            maxi=max(maxi,arr[i][0]);
        }
        vector<int>ans;
        while(true){
            auto ele=minH.top();
            int range=maxi-ele.first;
            minH.pop();
            if(range<minRange){
                minRange=range;
                ans={ele.first,maxi};
            }
            poin[ele.second]++;
             if (poin[ele.second] == arr[ele.second].size()) {
            break;  
        }
            minH.push({arr[ele.second][poin[ele.second]],ele.second});
            maxi=max(maxi,arr[ele.second][poin[ele.second]]);
        }
        return ans;
    }
};