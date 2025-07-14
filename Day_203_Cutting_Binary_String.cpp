#include <bits/stdc++.h>
using namespace std;

// Problem: Minimum cuts to segment a binary string into parts that are powers of 5
// Approach: Dynamic Programming

// Steps:
// 1. Initialize a DP array to store the minimum cuts needed for each prefix of the string.
// 2. Use a set to store powers of 5 up to a certain limit (1 << 30).
// 3. Iterate through the string, and for each position, check all possible segments that
//    can be formed starting from that position.
// 4. If the segment is a power of 5 and the next position has a valid cut, update the DP array.
// 5. Return the minimum cuts needed for the entire string or -1 if it's not possible.

// Time Complexity: O(n^2) where n is the length of the string
// Space Complexity: O(n) for the DP array.

class Solution {
  public:
    int cuts(string &s) {
        int n = s.size() , INF = n + 1;
        vector<int> dp(n + 1 , INF);
        dp[n] = 0;
        
        unordered_set<int> p5;
        for(long long x = 1; x <= (1LL << min(n , 30)); x *= 5)
        p5.insert(x);
        
        for(int i = n - 1 ; i >= 0 ; --i){
            if(s[i] == '0') continue;
            long long num = 0;
            for(int j = i ; j < n ; ++j){
                num = (num << 1) + (s[j] - '0');
                if(num > (1LL << 30)) break;
                if(p5.count(num) && dp[j + 1] != INF){
                    dp[i] = min(dp[i] , 1 + dp[j + 1]);
                }
            }
        }
        
        return dp[0] >= INF ? -1 : dp[0];
        
    }
};