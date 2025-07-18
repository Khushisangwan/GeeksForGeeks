#include<bits/stdc++.h>
using namespace std;
// Problem: Find the product of the three largest distinct integers from 1 to n that are not divisible by 2 or 3.
// Approach: The three largest integers that are not divisible by 2 or 3 can be
//           determined based on the value of n. If n is even and divisible by 3, we can directly use n, n-1, and n-2.
//           If n is even but not divisible by 3, we can use n, n


class Solution {
  public:
    int lcmTriplets(int n) {
        // code here
          if(n<=2) return n;
        if(n%2==0 && n%3==0)
            return (n-2)*(n-1)*(n-3);
        else if(n%2==0)
            return n*(n-1)*(n-3);
        return n*(n-1)*(n-2);
    }
};