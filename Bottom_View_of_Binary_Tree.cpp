#include <bits/stdc++.h>
using namespace std;

// Problem: Find the bottom view of a binary tree
// Approach: Use a map to store the last node at each horizontal distance Use a queue to perform a level order traversal

// Steps:
// 1. Create a map to store the last node at each horizontal distance
// 2. Create a queue to perform a level order traversal
// 3. Push the root node into the queue with a horizontal distance of 0
// 4. While the queue is not empty, do the following:
//    a. Pop the front element from the queue
//    b. Update the map with the current node's data at the current horizontal distance
//    c. If the current node has a left child, push it into the queue with a horizontal distance of -1
//    d. If the current node has a right child, push it into the queue with a horizontal distance of +1
// 5. After the level order traversal, extract the values from the map and return them as the bottom view

// Time Complexity: O(n), where n is the number of nodes in the tree
// Space Complexity: O(n), for the map and queue

/*
struct Node
{
    int data;
    Node* left;
    Node* right;
};
*/

class Solution {
  public:
    vector<int> bottomView(Node *root) {
         map<int, int>map;
        queue<pair<Node*, int>> q;
        q.push({root, 0});
        
        while(!q.empty()){
            int size = q.size();
            
            for(int i = 0;i<size;i++){
                auto front = q.front(); q.pop();
                
                map[front.second] = front.first->data;
                
                if(front.first->left)  q.push({front.first->left, front.second-1});
                if(front.first->right)  q.push({front.first->right, front.second+1});
            }
        }
        
        vector<int> ans;
        
        for(auto i : map){
            ans.push_back(i.second);
        }
        
        return ans;
    }
};