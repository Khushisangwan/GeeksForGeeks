#include<bits/stdc++.h>
using namespace std;
class Solution {
    int cs = 0; // cumulative sum to track sum of all nodes processed so far
  public:
    void transformTree(Node *root) {
        if(!root) return; // base case: if node is null, return
        
        int d = root->data; // store original data of current node
        
        // First process right subtree (larger values)
        transformTree(root->right);
        
        // Update current node with cumulative sum of all larger nodes
        root->data = cs;
        
        // Add original value to cumulative sum for next nodes
        cs += d;
        
        // Then process left subtree (smaller values)
        transformTree(root->left);
    }
};