#include <bits/stdc++.h>
using namespace std;
class Solution {
    public:
         int kthMissing(vector<int> &arr, int k) {
                // code here
                int n = arr.size();
                int left = 0, right = n - 1, mid;
                
                // If the first element is greater than k, then k is the answer
                if(arr[0] > k) {
                        return k;
                }
                
                // Binary search to find the position where kth missing number lies
                while(left <= right) {
                        mid = (left + right) / 2;
                        // Calculate how many numbers are missing up to arr[mid]
                        // arr[mid] - (mid+1) gives count of missing numbers before arr[mid]
                        if((arr[mid] - (mid + 1)) < k) {
                                left = mid + 1;
                        } else {
                                right = mid - 1;
                        }
                }
                
                // If right becomes -1, the kth missing number is k itself
                if(right == -1) {
                        return k;
                }
                
                // Calculate the kth missing number based on arr[right]
                // arr[right] + remaining missing numbers needed
                return arr[right] + (k - (arr[right] - (right + 1)));
        }
};