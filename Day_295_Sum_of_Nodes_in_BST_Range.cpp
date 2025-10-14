#include <bits/stdc++.h>
using namespace std;
class Solution {
    public:
        int nodeSum(Node* root, int l, int r) {
                // Base case: if node is null, return 0
                if(!root) return 0;
                
                int ans = 0;
                
                // If current node's value is greater than lower bound,
                // there might be valid nodes in left subtree
                if(root -> data > l) ans += nodeSum(root -> left, l, r);
                
                // If current node's value is less than upper bound,
                // there might be valid nodes in right subtree
                if(r > root -> data) ans += nodeSum(root -> right, l, r);
                
                // If current node's value is within the range [l, r],
                // include it in the sum
                if(root -> data >= l && root -> data <= r) ans += root -> data;
                
                return ans;
        }
};