#include <bits/stdc++.h>
using namespace std;

// Problem: Determine the minimum additional soldiers required to ensure at least half of the troops are "safe"
// Approach: Convert each troop's strength into the number of additional soldiers needed to make it divisible by k, 
//           then choose the smallest requirements for the required number of safe troops

// Steps:
// 1. Calculate the number of troops that must be safe: ceil(n / 2) = (n + 1) / 2.
// 2. For each troop, compute how many more soldiers are needed to make its strength divisible by k.
//    - If already divisible, the requirement is 0.
//    - Otherwise, requirement = k - (strength % k).
// 3. Sort the computed requirements in ascending order.
// 4. Pick the smallest `safe_troop` requirements and sum them to get the answer.
// 5. Return the total soldiers needed.

// Time Complexity: O(n log n) due to sorting the requirements array
// Space Complexity: O(1) additional space (in-place computation on input array)

class Solution {
  public:
    int minSoldiers(vector<int>& arr, int k) {
        int n=arr.size();
        int safe_troop=(n+1)/2;
        for(int i=0;i<n;i++)
            arr[i]=arr[i]%k!=0?k-arr[i]%k:0;
        
        sort(arr.begin(),arr.end());
        int i=0;
        int ans=0;
        while(safe_troop)
        {
            ans+=arr[i];
            i++;
            safe_troop--;
        }
        return ans;
    }
};