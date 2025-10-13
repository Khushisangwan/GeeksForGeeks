#include <bits/stdc++.h>
using namespace std;
class Solution {
    static Map<Node, Integer> m = new HashMap<>();  // Memoization map to store computed results
    
    public int getMaxSum(Node root) {
        // Base case: if node is null, return 0
        if(root == null) return 0;
        
        // If result is already computed, return cached result
        if(m.containsKey(root)) return m.get(root);
        
        // Case 1: Include current node
        // If we include current node, we cannot include its children
        // So we add current node's data and sum of grandchildren
        int withNode = root.data;
        
        // Add sum from left grandchildren
        if(root.left != null){
            withNode += getMaxSum(root.left.left);
            withNode += getMaxSum(root.left.right);
        }
        
        // Add sum from right grandchildren
        if(root.right != null){
            withNode += getMaxSum(root.right.left);
            withNode += getMaxSum(root.right.right);
        }
        
        // Case 2: Exclude current node
        // If we exclude current node, we can include its children
        int withoutNode = getMaxSum(root.left) + getMaxSum(root.right);
        
        // Take maximum of both cases
        int res = Math.max(withNode, withoutNode);
        
        // Store result in memoization map
        m.put(root, res);
        
        return res;
    }
}