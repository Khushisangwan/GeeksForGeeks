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
#include<bits/stdc++.h>
using namespace std;
class Solution {
    public:
        // Helper function to get inorder traversal of BST
        void getInorder(vector<int> &inorder,Node* root){
                if(root==NULL) return; // Base case: null node
                getInorder(inorder,root->left); // Traverse left subtree
                inorder.push_back(root->data); // Visit current node
                getInorder(inorder,root->right); // Traverse right subtree
        }
        
        vector<int> getKClosest(Node* root, int target, int k) {
                // Get sorted array from BST using inorder traversal
                vector<int> inorder;
                getInorder(inorder,root);
                int n=inorder.size();
                
                // Use max heap to maintain k closest elements
                // Pair format: {absolute_difference, node_value}
                priority_queue<pair<int,int>> pq;
                
                // Process each element in inorder array
                for(int i=0;i<n;i++){
                        // Push difference and value to max heap
                        pq.push({abs(inorder[i]-target),inorder[i]});
                        // Keep only k elements in heap
                        if(pq.size()>k) pq.pop();
                }
                
                // Extract k closest values from heap
                vector<int> ans;
                while(!pq.empty()){
                        ans.push_back(pq.top().second);
                        pq.pop();
                }
                return ans;
        }
};