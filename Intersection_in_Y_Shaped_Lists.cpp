/*
class Node {
public:
    int data;
    Node* next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};
*/
#include <bits/stdc++.h>
using namespace std;

// Node structure for linked list
class Node {
public:
    int data;
    Node* next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

class Solution {
  public:
    // Find intersection point of two linked lists using two-pointer technique
    Node* intersectPoint(Node* head1, Node* head2) {
        // Return NULL if either list is empty
        if (head1 == NULL || head2 == NULL) 
            return NULL;
        
        // Initialize pointers at the head of both lists
        Node *x1 = head1;
        Node *x2 = head2;
        
        // Traverse both lists; when pointers meet, they're at intersection
        while (x1 != x2) {
            // Move to next node, or switch to other list if reached end
            x1 = (x1 == nullptr) ? head2 : x1->next;
            x2 = (x2 == nullptr) ? head1 : x2->next;
        }
        
        // Return intersection node (or NULL if no intersection)
        return x2;
    }
};