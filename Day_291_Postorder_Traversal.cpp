/*
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
    // Helper function for recursive postorder traversal
    void post(Node* root, vector<int>& ans){
        // Base case: if current node is null, return
        if (!root) return;
        
        // Recursively traverse left subtree
        post(root->left, ans);
        
        // Recursively traverse right subtree
        post(root->right, ans);
        
        // Visit current node (add to result after visiting children)
        ans.push_back(root->data);
    }
  public:
    // Function to return postorder traversal of binary tree
    vector<int> postOrder(Node* root) {
        // Initialize result vector
        vector<int> ans;
        
        // Start recursive traversal
        post(root, ans);
        
        return ans;
    }
};