#include <bits/stdc++.h>
using namespace std;

/*
class Node {
public:
    int data;
    Node *left, *right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};
*/
// Solution class to check if a binary tree is symmetric
class Solution {
    public:
        // Helper function to check if two subtrees are mirror images
        bool isMirror(Node* left, Node* right) {
                // If both nodes are null, they are symmetric
                if (!left && !right) return true;

                // If only one node is null, they are not symmetric
                if (!left || !right) return false;

                // Check if current nodes have the same value and
                // their children are mirrors of each other
                return (left->data == right->data) &&
                             isMirror(left->left, right->right) &&
                             isMirror(left->right, right->left);
        }

        // Main function to check if the tree is symmetric
        bool isSymmetric(Node* root) {
                // An empty tree is symmetric
                if (!root) return true;
                // Check if left and right subtrees are mirrors
                return isMirror(root->left, root->right);
        }
};
