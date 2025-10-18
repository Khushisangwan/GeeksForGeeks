/*
class Node {
  public:
    int data;
    Node* left;
    Node* right;
    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};
*/
#include<bits/stdc++.h>
using namespace std;
class Solution {
    public:
        // Helper function to count total nodes in BST using inorder traversal
        void inorder(Node* root, int &count) {
                if (root == NULL) return;
                inorder(root->left, count);
                count++;
                inorder(root->right, count);
        }
        
        // Helper function to find the kth node in inorder traversal
        void findNodeHelper(Node* root, int &k, int &res) {
                if (root == NULL) return;
                findNodeHelper(root->left, k, res);
                k--; // Decrement k for current node
                if (k == 0) {
                        res = root->data; // Found the kth node
                        return;
                }
                findNodeHelper(root->right, k, res);
        }
        
        // Main function to find median of BST
        int findMedian(Node* root) {
                int Totalcount = 0;
                // Count total nodes in the BST
                inorder(root, Totalcount);
                
                // Handle empty tree
                if (Totalcount == 0) return 0;
                
                // For odd number of nodes, median is the middle element
                if (Totalcount % 2 != 0) {
                        int k = Totalcount / 2 + 1; // Position of median (1-indexed)
                        int res = 0;
                        findNodeHelper(root, k, res);
                        return res;
                } else {
                        // For even number of nodes, median is the lower middle element
                        int k1 = Totalcount / 2; // Position of lower middle element
                        //int k2 = k1 + 1; // Position of upper middle element (not used)
                        int res1 = 0, res2 = 0;
                        findNodeHelper(root, k1, res1);
                        //findNodeHelper(root, k2, res2); // Not calculating upper middle
                        return (res1); // Returning only lower middle element
                }
        }
};