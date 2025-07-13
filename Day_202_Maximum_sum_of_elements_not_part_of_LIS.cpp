#include <bits/stdc++.h>
using namespace std;

// Problem: Maximum sum of elements not part of Longest Increasing Subsequence (LIS)
// Approach: Dynamic Programming    

// Steps:
// 1. Initialize a DP array to store the length and sum of LIS ending at each index.
// 2. Iterate through the array and for each element, check all previous elements to find
//    the longest increasing subsequence that can be formed.
// 3. Update the DP array with the length and sum of the LIS.
// 4. Calculate the total sum of the array and find the minimum sum of the LIS.
// 5. Return the difference between the total sum and the minimum sum of the LIS.

// Time Complexity: O(n^2) where n is the number of elements in the array
// Space Complexity: O(n) for the DP array.

class Solution {
  public:
    
int nonLisMaxSum(vector<int>& arr) {
        // code here
        
        int n  = arr.size();
        
        vector<pair<int,int>>dp(n);
        
        int maxLen = 0;
        int minSum = 0;
        int totalSum = 0;
        
        for(int i = 0 ;  i < n ; i++)
        {
            int len = 0;
            int sum = 0;
            
            totalSum += arr[i];
            
            for(int j = i-1 ; j >= 0 ; j--)
            {
                if(arr[i] > arr[j] && dp[j].first >= len){
                    
                    if(dp[j].first > len){
                        len = dp[j].first;
                        sum = dp[j].second;
                    }
                    else if(dp[j].second < sum){
                        sum = dp[j].second;
                    }
                    
                }
            }
            
            len++;
            sum += arr[i];
            
            dp[i] = {len,sum};
            
            
          
        }
        
        for(int i = 0 ; i < n ; i++)
        {
            if(dp[i].first >= maxLen){
                
                if(dp[i].first > maxLen){
                    minSum = dp[i].second;
                    maxLen = dp[i].first;
                }
                else{
                    minSum = min(minSum, dp[i].second);
                }
            }
        }
        
        return totalSum - minSum;
    }
};