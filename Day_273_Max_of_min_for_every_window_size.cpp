
#include <bits/stdc++.h>
using namespace std;
class Solution {
  public:
    vector<int> maxOfMins(vector<int>& arr) {
        // Your code here
        stack<int>s;
        int n = arr.size();
        vector<int>left(n);
        vector<int>right(n);
        vector<int>ans(n, 0);
        
        // 1st loop for left->
        
        for(int i =0; i<n;i++){
             while(!s.empty() && arr[i]<=arr[s.top()]){
                 s.pop();
             }
             if(s.empty()){
                 left[i] = -1;
             }
             else{
                 left[i] = s.top();
             }
             
             s.push(i);
        }
        // stack ko khali kr dunga
        while(!s.empty()){
            s.pop();
        }
        
        // second loop for right->
        for(int i =n-1; i>=0; i--){
            while(!s.empty() && arr[i]<arr[s.top()]){
                s.pop();
            }
            if(s.empty()){
                right[i] = n; // waha tha i
            }
            else{
                right[i]  = s.top();
            }
            s.push(i);
        }
        
        for(int i =0; i<n; i++){
            int mx = right[i]-left[i]-1;
            ans[mx-1] = max(ans[mx-1], arr[i]);
        }
        for(int i = n-2; i>=0; i--){
            ans[i] = max(ans[i], ans[i+1]);
        }
        return ans;
        
    }
};

