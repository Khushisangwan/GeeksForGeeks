
#include <bits/stdc++.h>
using namespace std;
class Solution {
    public:
        vector<int> maxOfMins(vector<int>& arr) {
                // Your code here
                stack<int>s;
                int n = arr.size();
                vector<int>left(n);   // stores index of previous smaller element
                vector<int>right(n);  // stores index of next smaller element
                vector<int>ans(n, 0); // result array for max of mins for each window size
                
                // Find previous smaller element for each element
                for(int i = 0; i < n; i++){
                         // Pop elements that are greater than or equal to current element
                         while(!s.empty() && arr[i] <= arr[s.top()]){
                                 s.pop();
                         }
                         // If stack is empty, no smaller element exists on left
                         if(s.empty()){
                                 left[i] = -1;
                         }
                         else{
                                 left[i] = s.top(); // index of previous smaller element
                         }
                         
                         s.push(i); // push current index
                }
                
                // Clear the stack for next use
                while(!s.empty()){
                        s.pop();
                }
                
                // Find next smaller element for each element
                for(int i = n-1; i >= 0; i--){
                        // Pop elements that are greater than current element
                        while(!s.empty() && arr[i] < arr[s.top()]){
                                s.pop();
                        }
                        // If stack is empty, no smaller element exists on right
                        if(s.empty()){
                                right[i] = n; // use n as boundary
                        }
                        else{
                                right[i] = s.top(); // index of next smaller element
                        }
                        s.push(i); // push current index
                }
                
                // Calculate maximum window size where each element can be minimum
                for(int i = 0; i < n; i++){
                        int mx = right[i] - left[i] - 1; // window size where arr[i] is minimum
                        ans[mx-1] = max(ans[mx-1], arr[i]); // update answer for this window size
                }
                
                // Fill remaining positions with maximum values from larger windows
                for(int i = n-2; i >= 0; i--){
                        ans[i] = max(ans[i], ans[i+1]);
                }
                
                return ans;
        }
};
