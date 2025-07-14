class Solution {
  public:
    int cuts(string &s) {
        // code here
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