/*
class Node {
  public:
    int data;
    Node* left;
    Node* right;

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
        int kthSmallest(Node *root, int &k) {
             // Base case: if node is NULL, return -1
             if(root==NULL)
                return -1;
                
                // Recursively search in left subtree (smaller elements)
                int left=kthSmallest(root->left,k);
                
                // If kth smallest found in left subtree, return it
                if(left!=-1)
                {
                return left;
                }
                
                // Process current node - decrement k
                k--;
                
                // If this is the kth node, return its data
                if(k==0)
                {
                return root->data;
                }
                
             // Search in right subtree (larger elements)
             return kthSmallest(root->right,k); 
        }
};