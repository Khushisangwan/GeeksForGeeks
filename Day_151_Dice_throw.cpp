#include <bits/stdc++.h>
using namespace std;
class Solution {
  public:
    int noOfWays(int m, int n, int x) {
        // code here
         vector<int> curr(x + 1, 0), next(x + 1, 0);
        next[0] = 1;
        
        for(int i = n - 1; i >= 0; i--) {
            for(int s = 1; s <= x; s++) {
                curr[s] = curr[s - 1] + next[s - 1] - 
                ((s - 1 - m >= 0) ? next[s - 1 - m] : 0);
            }
            next = curr;
        }
        
        return next[x];
    }
};