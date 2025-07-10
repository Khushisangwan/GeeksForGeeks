#include <bits/stdc++.h>
using namespace std;
// This code is part of a solution to find the longest string that can be built one character at a time from an array of strings.
// The solution uses a map to track which strings can be formed and returns the longest one.
// The code is designed to work with the C++14 standard.
class Solution {
  public:
    string longestString(vector<string> &arr) {
        // code here
        sort(arr.begin(),arr.end());
        unordered_map<string,bool>mp;
        
        string ans="";
        for(int j=0;j<arr.size();j++){
            string x=arr[j].substr(0,arr[j].size()-1);
            if(arr[j].size()==1 || mp.find(x)!=mp.end()){
                mp[arr[j]]=1;
                if(ans.size()<arr[j].size()) ans=arr[j];
            }
        }
        return ans;
    }
};