#include <bits/stdc++.h>
using namespace std;
class Solution {
    public:
     // Compute the minimum cost to connect all ropes.
     // We always connect the two smallest ropes first (greedy),
     // because that minimizes the incremental cost at each step.
     // Time complexity: O(n log n) due to heap operations.
     int minCost(vector<int>& arr) {
                int count = 0; // accumulated total cost

                // min-heap to retrieve the smallest two rope lengths quickly
                priority_queue<int, vector<int>, greater<int>> pq;

                // push all rope lengths into the min-heap
                for (auto it : arr)
                        pq.push(it);

                // combine ropes until only one rope remains
                while (pq.size() != 1) {
                        // take the two smallest ropes
                        int first = pq.top();
                        pq.pop();
                        int second = pq.top();
                        pq.pop();

                        // cost to connect these two ropes
                        int total = first + second;
                        // add the cost to the running total
                        count += total;

                        // push the combined rope back into the heap
                        pq.push(total);
                }

                return count;
        }
};