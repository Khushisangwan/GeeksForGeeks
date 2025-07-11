#include<bits/stdc++.h>
using namespace std;
// This code is part of a solution to count the number of ways to form consecutive sequences of 1s in a binary representation.
// The solution uses a mathematical approach based on Fibonacci numbers to calculate the result.

class Solution {
  public:
  int fib(int n){
      int first=1,second=1;
      int sum=0;
      for(int i=3;i<=n;i++){
          sum=first+second;
          first=second;
          second=sum;
      }
      return sum;
  }
    int countConsec(int n) {
        // code here
        return (1<<n) - fib(n+2);
    }
};