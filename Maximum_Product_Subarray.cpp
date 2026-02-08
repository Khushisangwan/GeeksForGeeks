#include<bits/stdc++.h>
using namespace std;
class Solution {
    public:
        int maxProduct(vector<int> &arr) {
                int n = arr.size() , ans = INT_MIN;
                int pref = 1 , suff = 1;
                
                // Iterate through the array
                for(int i = 0; i < n; i++){
                        // Multiply prefix (left to right)
                        pref *= arr[i];
                        // Multiply suffix (right to left)
                        suff *= arr[n - i - 1];
                        // Update maximum product found so far
                        ans = max({ans , pref , suff});
                        
                        // Reset prefix to 1 if it becomes 0
                        if(pref == 0)
                                pref = 1;
                        // Reset suffix to 1 if it becomes 0
                        if(suff == 0)
                                suff = 1;
                }
                return ans;
        }
};