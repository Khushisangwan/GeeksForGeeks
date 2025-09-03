/*
class Node {
  public:
    int data;
    Node *next;
    Node *prev;
    Node(int val) {
        data = val;
        next = NULL;
      a  prev = NULL;
    }
};

*/
#include <bits/stdc++.h>
using namespace std;
class Solution {
    public:
        Node *reverse(Node *head) {
                Node * temp = head;  // Start from the head of the list
                
                // Traverse through the entire doubly linked list
                while (temp) {
                        Node * node = temp->next;  // Store the next node before modifying pointers
                        
                        // Swap the next and prev pointers of current node
                        temp->next = temp->prev;
                        temp->prev = node;
                        
                        // If we've reached the end of the original list, break
                        if (!node) break;
                        
                        temp = node;  // Move to the next node in the original list
                }
                
                // temp now points to the new head (originally the tail)
                return temp;
        }
};