#include<bits/stdc++.h>
using namespace std;
class Solution {
  public:
    bool ValidCorner(vector<vector<int> >& mat) {
        // code here
           int n = mat.size(); // rows
        int m = mat[0].size();// cols
        
        // traverse the rows
        for(int i =0; i < n; i++){
            
            for(int j = i+1; j < n; j++){
                int arr[m];
                int count  = 0;
                for(int k =0; k < m; k++){
                    arr[k] = mat[i][k] + mat[j][k];
                    if(arr[k] == 2) count++;
                    if(count == 2)return true;
                }
            }
        }
        return false;
    }
};