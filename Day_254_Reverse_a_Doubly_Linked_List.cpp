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
        Node * temp=head;
        while (temp){
            Node * node = temp->next;
            temp->next = temp->prev;
            temp->prev = node;
            if(!node) break;
            temp = node;
        }
        
        return temp;
    }
};