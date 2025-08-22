#include <bits/stdc++.h>
using namespace std;
// Problem: Find the median in a row-wise sorted matrix
// Approach: Use binary search on the value range to find the median
// Steps:
// 1. Determine the minimum and maximum elements in the matrix.
// 2. Use binary search on the range [min, max] to find the median.
// 3. For each mid value in the binary search, count how many elements are less than or equal to mid.
// 4. If the count is less than or equal to half the total number of elements
//    (i.e., n*m/2), it means the median is greater than mid, so search in the higher half.
// 5. If the count is greater than half the total number of elements, it means
//    the median is less than or equal to mid, so search in the lower half.
// Time Complexity: O(32 * n * m) = O(n * m), where
//                  32 is the number of bits required to represent the range of values (assuming 32-bit integers).
// Space Complexity: O(1) for the binary search, O(1) for counting
    
class Solution {
  public:
    int median(vector<vector<int>> &mat) {
        // code here
         int n=mat.size();
        int m=mat[0].size();
        int count;
        int l=INT_MAX;
        int h=INT_MIN;
        for(int i=0;i<n;i++)
        {
            l=min(l,mat[i][0]);
        }
        for(int i=0;i<n;i++)
        {
            h=max(h,mat[i][m-1]);
        }
        int ans=0;
        while(l<=h)
        {
            int mid=(l+h)/2;
            count=0;
            for(int i=0;i<n;i++)
            {
                for(int j=0;j<m;j++)
                {
                    if(mat[i][j]<=mid)
                    {
                        count++;
                    }
                    else
                    {
                        break;
                    }
                }
            }
            if(n*m-count<=count)
            {
                ans=mid;
                h=mid-1;
            }
            else
            {
                l=mid+1;
            }
        }
        return ans;
    }
};
