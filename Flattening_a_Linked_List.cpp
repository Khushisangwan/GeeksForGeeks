/*
class Node {
public:
    int data;
    Node* next;
    Node* bottom;

    Node(int x) {
        data = x;
        next = NULL;
        bottom = NULL;
    }
};
*/
#include<bits/stdc++.h>
using namespace std;
class Solution {
    public:
    
        // Comparator for min-heap based on node data
        struct Compare {
            bool operator()(Node* a, Node* b) {
                return a->data > b->data;
            }
        };
        
        // Flatten the linked list using a priority queue
        Node *flatten(Node *root) {
            // Min-heap to store nodes in sorted order
            priority_queue<Node*, vector<Node*>, Compare> pq;
            
            Node* temp = root;  // Pointer to build the flattened list
            Node* ans = temp;   // Store the head of flattened list
            pq.push(temp);
            
            while(!pq.empty()) {
                // Extract node with minimum data
                Node* curr = pq.top();
                pq.pop();
                
                // Push next pointer to queue if exists
                if(curr->next)
                    pq.push(curr->next);
                
                // Push bottom pointer to queue if exists
                if(curr->bottom)
                    pq.push(curr->bottom);
                
                // Skip the root node
                if(curr == root) continue;
                
                // Connect current node to the flattened list
                temp->bottom = curr;
                temp = temp->bottom;
            }
            
            return ans;
        }
};