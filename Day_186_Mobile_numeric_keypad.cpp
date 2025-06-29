class Solution {
  public:
    int getCount(int n) {
        vector<vector<int>> adj={{0,8}, {1,2,4}, {1,2,3,5}, {2,3,6}, {1,4,5,7},
                        {2,4,5,6,8}, {3,5,6,9}, {4,7,8}, {5,7,8,9,0}, {6,8,9}};
        vector<int> v(10,1), dp(10,1);
        for(int i=1;i<n;i++){
            for(int j=0;j<10;j++){
                dp[j]=0;
                for(auto k:adj[j]){
                    dp[j] += v[k];
                }
            }
            v = dp;
        }
        return accumulate(dp.begin(), dp.end(), 0);
    }
};