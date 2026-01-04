#include <bits/stdc++.h>
using namespace std;
class Solution {
    public:
        void sort012(vector<int>& arr) {
                // Count occurrences of 0s, 1s, and 2s
                int cnt0=0,cnt1=0,cnt2=0;
                for(int i=0;i<arr.size();i++){
                        if(arr[i]==0){
                                cnt0++;
                        }else if(arr[i]==1){
                                cnt1++;
                        }else{
                                cnt2++;
                        }
                }
                
                // Reconstruct array: place all 0s first
                int i=0;
                while(cnt0--){
                        arr[i++]=0;
                }
                // Then place all 1s
                while(cnt1--){
                        arr[i++]=1;
                }
                // Finally place all 2s
                while(cnt2--){
                        arr[i++]=2;
                }
        }
};
