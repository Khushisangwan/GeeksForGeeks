#include <bits/stdc++.h>
using namespace std;
class Solution {
    public:
        vector<string> generateBinary(int n) {
                // Initialize result vector with first binary number "1"
                vector<string> v={"1"};
                
                // Generate remaining n-1 binary numbers
                for(int i=1,j=0,x=0;i<n;i++){
                        // Append current bit (0 or 1) to the j-th generated number
                        v.push_back(v[j] + to_string(x));
                        
                        // Toggle bit between 0 and 1
                        x^=1;
                        
                        // Move to next base number when we've added both 0 and 1
                        if(x==0) j++;
                }
                return v;
        }
};