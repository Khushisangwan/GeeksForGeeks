#include<bits/stdc++.h>
using namespace std;
// Problem: Maximum Sum Combination
// Link: https://practice.geeksforgeeks.org/problems/maximum-sum-combination/
class Solution {
    public:
        vector<int> topKSumPairs(vector<int>& a, vector<int>& b, int k) {
                // Sort both arrays in descending order to get largest elements first
                int n = a.size(), m = b.size();
                sort(a.begin(), a.end(), greater<int>());
                sort(b.begin(), b.end(), greater<int>());
                
                // Min-heap to keep track of top k sums
                priority_queue<int, vector<int>, greater<int>> pq;
                
                // Only consider the first k elements from both arrays
                for (int i = 0; i < k; i++) {
                        for (int j = 0; j < k; j++) {
                                int sum = a[i] + b[j];
                                // If heap is full and current sum is less than the smallest in heap, break inner loop
                                if (pq.size() == k && sum < pq.top()) break;
                                pq.push(sum);
                                // Maintain heap size to k
                                if (pq.size() > k) pq.pop();
                        }
                }
                
                // Extract results from heap into a vector
                vector<int> ans;
                while (!pq.empty()) {
                        ans.push_back(pq.top());
                        pq.pop();
                }
                // Reverse to get results in descending order
                reverse(ans.begin(), ans.end());
                
                return ans;
        }
};