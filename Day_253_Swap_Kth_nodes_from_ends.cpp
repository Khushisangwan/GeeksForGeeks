/*
class Node {
  public:
    int data;
    Node *next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};
*/
#include<bits/stdc++.h>
using namespace std;
class Solution {
    public:
        Node* swapKth(Node* head, int k) {
                // Find the length of the linked list
                Node* start = head;
                int len = 0;
                while(start) {
                        len++;
                        start = start->next;
                }
                
                // If k is greater than length, no swap needed
                if(k > len) return head;
                
                // Calculate positions: kth from start and kth from end
                int s = k;              // kth node from start
                int e = len - k + 1;    // kth node from end
                
                // If both positions are same, no swap needed
                if(e == s) return head;
                
                // Find the nodes at positions s and e
                start = head;
                int idx = 1;
                Node* point1;  // kth node from start
                Node* point2;  // kth node from end
                
                while(start) {
                        if(idx == s) point1 = start;
                        else if(idx == e) point2 = start;
                        start = start->next;
                        idx++;
                }
                
                // Swap the data of the two nodes
                int temp = point1->data;
                point1->data = point2->data;
                point2->data = temp;
                
                return head;
        }
};