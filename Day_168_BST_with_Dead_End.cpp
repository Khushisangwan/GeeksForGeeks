/*The Node structure is
class Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int x){
        data = x;
        left = NULL;
        right = NULL;
    }
};*/
#include <bits/stdc++.h>
using namespace std;
// This code checks if a binary search tree (BST) has a dead end.

class Solution{
    public:
        vector<int> arr, leaf; // arr stores inorder traversal, leaf stores leaf node values
        
        // Helper function to perform inorder traversal and collect node values and leaves
        void inorder(Node* node){
                if(!node)
                        return;
                
                inorder(node->left);
                arr.push_back(node->data); // Add current node's value to arr
                if(!node->left && !node->right)
                        leaf.push_back(node->data); // If leaf, add to leaf vector
                inorder(node->right);
        }
        
        // Function to check if the BST contains a dead end
        bool isDeadEnd(Node *root)
        {
                arr = {0}; // Add 0 as a virtual lower bound for BST
                leaf = {};
                inorder(root); // Fill arr and leaf vectors
                
                int j = 0;
                // Traverse arr and leaf to check for dead ends
                for(int i = 1; i < arr.size() && j < leaf.size(); ++i){
                        if(arr[i] == leaf[j]){
                                // If both neighbors of a leaf are consecutive, it's a dead end
                                if(arr[i-1] == leaf[j] - 1 && arr[i+1] == leaf[j] + 1)
                                        return true;
                                ++j;
                        }
                }
                
                return false; // No dead end found
        }
};