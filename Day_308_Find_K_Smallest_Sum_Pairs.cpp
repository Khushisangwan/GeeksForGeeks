#include<bits/stdc++.h>
using namespace std;
class Solution {
    public:
        // Return k pairs (one element from arr1 and one from arr2) with the smallest sums.
        vector<vector<int>> kSmallestPair(vector<int> &arr1, vector<int> &arr2, int k) {
                // Use a min-heap (priority_queue with greater comparator) keyed by the sum.
                // Each heap element is: {sum, {val_from_arr1, val_from_arr2}}
                priority_queue<pair<int, pair<int, int>>, 
                vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>>pq;

                int n = arr1.size();
                int m = arr2.size();

                // Only need to consider up to k elements from each array initially because
                // any pair using an index >= k cannot be among the k smallest sums
                // when both arrays are sorted (or in general when limiting candidates).
                for (int i = 0; i < min(k, n); i++) {
                        for (int j = 0; j < min(m, k); j++) {
                                // push pair (sum, {a, b}) onto heap
                                pq.push({arr1[i] + arr2[j], {arr1[i], arr2[j]}});
                        }
                }

                vector<vector<int>> ans;

                // Extract up to k smallest-sum pairs from the min-heap.
                while (!pq.empty() && ans.size() < k) {
                        ans.push_back({pq.top().second.first, pq.top().second.second});
                        pq.pop();
                }

                return ans;
        }
};