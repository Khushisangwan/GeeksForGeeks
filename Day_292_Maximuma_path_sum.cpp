/*
class Node {
public:
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/
#include <bits/stdc++.h>
using namespace std;
class Solution {
    public:
        // Main function to find the maximum path sum in the binary tree
        int findMaxSum(Node *root) {
                int maxSum = INT_MIN;  // Initialize with minimum possible value
                solve(root, maxSum);   // Call helper function
                return maxSum;
        }

        private:
                // Helper function that returns the maximum sum of a path starting from current node
                // and updates the global maximum path sum
                int solve(Node *root, int &maxSum) {
                        // Base case: if node is null, return 0
                        if (root == nullptr) {
                                return 0;
                        }
        
                        // Get maximum sum from left subtree (ignore negative paths)
                        int left = max(0, solve(root->left, maxSum));
                        
                        // Get maximum sum from right subtree (ignore negative paths)
                        int right = max(0, solve(root->right, maxSum));
        
                        // Update global maximum considering path through current node
                        maxSum = max(maxSum, left + right + root->data);
        
                        // Return maximum sum of path starting from current node
                        // (can only go through one side to maintain path property)
                        return root->data + max(left, right);
                }
};