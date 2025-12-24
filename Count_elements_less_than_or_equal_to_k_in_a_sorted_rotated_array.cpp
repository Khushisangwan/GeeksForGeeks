#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    // Finds the pivot point (start of rotation) in a rotated sorted array
    int FindPivot(vector<int> &arr)
    {
        int n = arr.size();
        int start = 0, end = n - 1, ans = 0;
        // Binary search to find the pivot
        while (start <= end)
        {
            int mid = (start + end) / 2;
            // If mid element is >= first element, pivot is on the right
            if (arr[mid] >= arr[0])
                start = mid + 1;
            // Otherwise, pivot is on the left or at mid
            else
                ans = mid, end = mid - 1;
        }
        return ans;
    }

    // Counts elements <= x in the range [l, r] using binary search
    int Count(int l, int r, int x, vector<int> &arr)
    {
        // Find the first position where element > x
        int idx = upper_bound(arr.begin() + l, arr.begin() + r + 1, x) - arr.begin();
        // Count of elements <= x in this range
        int cnt = idx - l;
        return cnt;
    }

    // Main function: counts elements <= x in a rotated sorted array
    int countLessEqual(vector<int> &arr, int x)
    {
        // Find the pivot point
        int Pivot = FindPivot(arr);
        int ans = 0, n = arr.size();
        // Sum counts from both sorted parts
        ans = Count(0 , Pivot - 1, x , arr) + Count(Pivot , n - 1 , x , arr);
        return ans;
    }
};