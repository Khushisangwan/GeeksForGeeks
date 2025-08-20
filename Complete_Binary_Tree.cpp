#include <bits/stdc++.h>
using namespace std;

// Problem: Check if a binary tree is complete
// Approach: Use level order traversal to check if all nodes are filled before any NULL node.

// Steps:
// 1. Use a queue to perform level order traversal of the binary tree.
// 2. Initialize a flag to track if a NULL node has been encountered.
// 3. For each node, if it is NULL, set the flag to true.
// 4. If a non-NULL node is encountered after a NULL node, return false.
// 5. If the traversal completes without violations, return true.

// Time Complexity: O(n), where n is the number of nodes in the tree.
// Space Complexity: O(n) for the queue used in level order traversal.

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) : data(val), left(NULL), right(NULL) {}
}

class Solution {
  public:
    bool isCompleteBT(Node* root) {
        if(!root) return 1;
        queue<Node*> q;
        q.push(root);
        bool NULL_Encounter = false;
        
        while(!q.empty()){
            Node* cur = q.front();
            q.pop();
            
            if(cur == NULL){                    // if(!cur)
                NULL_Encounter = true;
            }
            else{
                if(NULL_Encounter) return 0;
                q.push(cur -> left);
                q.push(cur -> right);
            }   
        }
        
        return 1;
    }
};