#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    // Function to count the number of possible triangles.
    int countTriangles(vector<int>& arr) {
        int ans = 0;
        sort(arr.begin(), arr.end());
        
        for(int i=2; i<arr.size(); i++){
            int left = 0, right = i - 1;
            
            while(left < right){
                if(arr[left] + arr[right] > arr[i]){
                    ans += right - left;
                    right--;
                }
                else{
                    left++;
                }
            }
        }
        
        return ans;
    }
    
};

