/*
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int x) {
        data = x;
        left = right = NULL;
    }
};
*/
#include <bits/stdc++.h>
using namespace std;
class Solution {
    public:
        vector<int> bottomView(Node *root) {
                // code here
                
                // Map to store horizontal distance for each node
                unordered_map<Node*,int> omap;
                
                // Map to store nodes at each horizontal distance (ordered by distance)
                map<int,vector<Node*>> mapForOrder;
                
                // Queue for level order traversal
                queue<Node*> q;
                q.push(root);
                
                // Root node is at horizontal distance 0
                omap[root] = 0;
                mapForOrder[0].push_back(root);
                
                // Level order traversal to assign horizontal distances
                while(!q.empty()) {
                        int counter = q.size();
                        
                        // Process all nodes at current level
                        for(int i = 0; i < counter; i++) {
                                Node* vertex = q.front();
                                q.pop(); 
                                
                                int location = omap[vertex];
                                
                                // Left child gets horizontal distance - 1
                                if(vertex->left != NULL) {
                                        q.push(vertex->left);
                                        omap[vertex->left] = location - 1;
                                        mapForOrder[location - 1].push_back(vertex->left);
                                }
                                
                                // Right child gets horizontal distance + 1
                                if(vertex->right != NULL) {
                                        q.push(vertex->right);
                                        omap[vertex->right] = location + 1;
                                        mapForOrder[location + 1].push_back(vertex->right);
                                }
                        }
                }
                
                vector<int> ans;
                
                // For each horizontal distance, take the last node (bottom-most)
                for(auto i : mapForOrder) {
                        ans.push_back(i.second[i.second.size() - 1]->data);
                }
                
                return ans;
        }
};