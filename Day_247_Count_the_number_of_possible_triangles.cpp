#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
        // Function to count the number of possible triangles.
        int countTriangles(vector<int>& arr) {
                int ans = 0;
                // Sort the array to use two-pointer technique
                sort(arr.begin(), arr.end());
                
                // Fix the largest side of triangle (at index i)
                for(int i=2; i<arr.size(); i++){
                        int left = 0, right = i - 1;
                        
                        // Use two pointers to find valid triangles
                        while(left < right){
                                // If sum of two smaller sides > largest side, triangle is valid
                                if(arr[left] + arr[right] > arr[i]){
                                        // All elements from left to right-1 can form triangles with arr[right] and arr[i]
                                        ans += right - left;
                                        right--; // Move right pointer to check smaller values
                                }
                                else{
                                        // Sum is too small, move left pointer to get larger sum
                                        left++;
                                }
                        }
                }
                
                return ans;
        }
        
};

