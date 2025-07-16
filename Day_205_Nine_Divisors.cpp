#include<bits/stdc++.h>
using namespace std;
// Problem: Count numbers whose square has exactly 5 divisors
// Approach: Count Divisors of Squares
// Steps:
// 1. For each number i from 1 to sqrt(n), calculate i*i.
// 2. For each square, count its divisors by iterating from 1 to sqrt(i*i).
// 3. If the count of divisors is exactly 5, increment the answer.
// 4. Return the total count of such numbers.
// Time Complexity: O(sqrt(n) * sqrt(n)) where n is the input number
// Space Complexity: O(1) since we are using a constant amount of space.

class Solution {
  public:
    int countNumbers(int n) {
        int ans = 0;
        for(int i=1;i*i<=n;i++){
            int ct = 0;
            for(int j=1;j*j<=i*i;j++){
                if((i*i)%j == 0){
                    ct++;
                    if(ct > 5)break;
                }
            }
            if(ct == 5){
                ans++;
            }
        }
        return ans;
    }
};