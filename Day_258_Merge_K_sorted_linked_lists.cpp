/*Linked list Node structure

struct Node
{
    int data;
    Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }

};
*/
#include<bits/stdc++.h>
using namespace std;
class Solution {
    public:
    
        // Helper function to merge two sorted linked lists
        Node* mergeTwo(Node* h1, Node* h2){
                // Create a dummy head to simplify merging logic
                Node* dummyHead = new Node(-1);
                Node* curr = dummyHead;
                
                // Compare nodes from both lists and link the smaller one
                while(h1 != NULL && h2 != NULL){
                        if(h1->data <= h2->data){
                                curr->next = h1;
                                h1 = h1->next;
                        }
                        else{
                                curr->next = h2;
                                h2 = h2->next;
                        }
                        curr = curr->next;
                }
                
                // Attach remaining nodes from the non-empty list
                if(h1 != NULL){
                        curr->next = h1;
                }
                else{
                        curr->next = h2;
                }
                
                // Return the merged list (skip dummy head)
                return dummyHead->next;
        }
        
        // Main function to merge k sorted linked lists
        Node* mergeKLists(vector<Node*>& arr) {
                Node* res = NULL;
                // Merge each list one by one with the result
                for(Node* node : arr){
                        res = mergeTwo(res, node);
                }
                return res;
        }
};
