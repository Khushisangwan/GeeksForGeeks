#include <bits/stdc++.h>
using namespace std;
class Solution {
    public:
        int minCandy(vector<int> &arr) {
                int n = arr.size();
                int sum = 1;  // Start with 1 candy for the first element
                int i = 1;
                
                while(i < n) {
                        // If current element equals previous, give 1 candy
                        if(arr[i] == arr[i-1]) {
                                sum += 1;
                                i++;
                        }
                        
                        // Count increasing sequence and add candies
                        int peak = 1;
                        while(i < n && arr[i] > arr[i-1]) {
                                peak += 1;
                                sum += peak;
                                i++;
                        }
                        
                        // Count decreasing sequence and add candies
                        int down = 1;
                        while(i < n && arr[i] < arr[i-1]) {
                                sum += down;
                                down++;
                                i++;
                        }
                        
                        // If descent is longer than ascent, add extra candies at the peak
                        if(down > peak) {
                                sum += (down - peak);
                        }
                }
                return sum;
        }
};