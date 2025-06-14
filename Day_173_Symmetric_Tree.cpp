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

class Solution {
  public:
    // Helper function to check mirror symmetry
    bool isMirror(Node* left, Node* right) {
        // Both nodes are null -> symmetric
        if (!left && !right) return true;

        // Only one is null -> not symmetric
        if (!left || !right) return false;

        // Check values and mirror children
        return (left->data == right->data) &&
               isMirror(left->left, right->right) &&
               isMirror(left->right, right->left);
    }

    bool isSymmetric(Node* root) {
        // A tree is symmetric if it's a mirror of itself
        if (!root) return true;
        return isMirror(root->left, root->right);
    }
};
