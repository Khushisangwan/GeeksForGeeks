#include <bits/stdc++.h>
using namespace std;

// Problem: Egg Dropping Puzzle
// Approach: Use a combination of iterative halving and binary search to minimize the number of trials needed to find the critical floor

// Steps:
// 1. If there is only one egg, the number of trials is equal to the number of floors.
// 2. If there are two eggs, we can use a halving strategy to reduce the number of trials.
// 3. For more than two eggs, we can use binary search to find the minimum number of trials needed.
// 4. The idea is to find the maximum number of floors that can be tested with a given number of trials and eggs.
// 5. We can calculate the number of floors that can be tested with `x` trials and `n` eggs using the formula:
//    F(x, n) = F(x-1, n-1) + F(x-1, n) + 1
//    where F(x, n) is the maximum number of floors that can be tested with `x` trials and `n` eggs.
// 6. We can use binary search to find the minimum number of trials needed to test `k` floors with `n` eggs.

// Time Complexity: O(log k) for the halving and O(sqrt(k)) for the binary search, leading to an overall complexity of O(sqrt(k) * log k)
// Space Complexity: O(1) as we are using a constant amount of space


class Solution {
  public:
    int eggDrop(int n, int k) {
        if(n == 1)return k;
        int oper = 0;
        while(k > 1 && n > 2)
        {
            k /= 2;
            n--;
            oper++;
        }
        int l = 0, r = k, extra = k;
        while(l <= r)
        {
            int mid = (l+r)/2;
            if((mid*(mid+1))/2 >= k)
            {
                extra = mid;
                r = mid-1;
            }
            else l = mid+1;
        }
        return oper+extra;
    }
};