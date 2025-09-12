class Solution {
    public:
        int getMinDiff(vector<int> &arr, int k) {
                // code here
                int n = arr.size();
                // If only one element, no difference possible
                if (n == 1) return 0;

                // Sort array to process heights in order
                sort(arr.begin(), arr.end());

                // Initial difference between max and min heights
                int ans = arr[n-1] - arr[0];

                // Calculate potential new smallest and largest values
                // by adding k to smallest and subtracting k from largest
                int smallest = arr[0] + k;
                int largest = arr[n-1] - k;

                // Try all possible partitions where we add k to elements [0...i]
                // and subtract k from elements [i+1...n-1]
                for (int i = 0; i < n-1; i++) {
                        // Minimum height after operations: either smallest or (arr[i+1] - k)
                        int minH = min(smallest, arr[i+1] - k);
                        // Maximum height after operations: either largest or (arr[i] + k)
                        int maxH = max(largest, arr[i] + k);

                        // Skip if any height becomes negative
                        if (minH < 0) continue;

                        // Update answer with minimum difference found so far
                        ans = min(ans, maxH - minH);
                }

                return ans;
        }
};