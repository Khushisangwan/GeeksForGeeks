#include <bits/stdc++.h>
using namespace std;
class Solution {
    public:
        vector<int> zigZagTraversal(Node* root) {
                vector<int> ans;  // Final result array
                queue<Node*> q;   // Queue for level order traversal
                q.push(root);
                bool f = 0;       // Flag to alternate zigzag direction (0: left-to-right, 1: right-to-left)
                
                while(!q.empty()){
                        int size = q.size();  // Number of nodes in current level
                        vector<int> v;        // Store current level nodes
                        
                        // Process all nodes in current level
                        for(int i = 0; i < size; i++){
                                Node* front = q.front(); 
                                q.pop();
                                v.push_back(front->data);
                                
                                // Add children to queue for next level
                                if(front->left) q.push(front->left);
                                if(front->right) q.push(front->right);
                        }
                        
                        // Reverse current level if flag is true (right-to-left)
                        if(f) reverse(v.begin(), v.end());
                        f = !f;  // Toggle direction for next level
                        
                        // Add current level to final result
                        ans.insert(ans.end(), v.begin(), v.end());
                }
                return ans;
        }
};