#include <bits/stdc++.h>
using namespace std;
class Solution {
  public:
    int maxWater(vector<int> &arr) {
        // code here
        int l = 0;
        int h = arr.size() - 1;
        
        int mx = 0;
        while(l <= h){
            mx = max(mx, (h - l) * min(arr[l], arr[h]));
            if(arr[l] < arr[h]) l++;
            else h--;
        }
        return mx;
    }
};