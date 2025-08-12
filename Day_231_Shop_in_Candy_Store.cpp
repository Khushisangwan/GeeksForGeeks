#include<bits/stdc++.h>
using namespace std;
// Problem Statement: Calculate the minimum and maximum cost of candies with a k-free offer
// Approach: Sort the prices and calculate the minimum and maximum costs based on the k-free offer.
// Steps:
// 1. Sort the prices of candies in ascending order.
// 2. For minimum cost, buy the cheapest candies and skip k candies after each purchase.
// 3. For maximum cost, buy the most expensive candies and skip k candies after each purchase.
// Time Complexity: O(n log n) for sorting, where n is the number of candies.
// Space Complexity: O(1) for the calculations, as we only use a few variables.
class Solution {
  public:
    vector<int> minMaxCandy(vector<int>& prices, int k) {
        sort(prices.begin(),prices.end());
        int n = prices.size();
        int mini =0, maxi = 0;
        
        int j = n-1;
        
        // minimum calculation 
        for (int i = 0 ; i < n && i <= j ; i++){
            mini += prices[i];
            j -= k;
        }
        
        j=0;
        
        // maximum calculation 
        for (int i = n-1 ; i >= 0 && i >= j ; i--){
            maxi += prices[i];
            j += k;
        }
        
        return {mini,maxi};
    }
};