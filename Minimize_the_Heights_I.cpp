class Solution {
  public:
    void solve(int idx, int sum, int n, vector<int>nums, set<int>&ans, vector<vector<bool>>&dp){
        if(idx >= n){
            ans.insert(sum);
            return;
        }
        
        if(dp[idx][sum]) return;
        
        dp[idx][sum] = true;
        
        solve(idx+1 , sum , n , nums , ans , dp);
        solve(idx+1 , sum + nums[idx] , n , nums , ans , dp);
    }
 
    vector<int> DistinctSum(vector<int>nums){
        int n = nums.size();
        int maxSum = accumulate(nums.begin() , nums.end() , 0);
        vector<vector<bool>>dp(n , vector<bool>(maxSum + 1 , false));
        set<int>ans;

        solve(0 , 0 , n , nums , ans , dp);
        return vector<int>(ans.begin() , ans.end());
    }
};