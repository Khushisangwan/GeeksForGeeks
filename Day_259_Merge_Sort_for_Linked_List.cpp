
/*
The structure of linked list is the following

struct Node {
    int data;
    Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }
};
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    // Function to sort the given linked list using Merge Sort.
    Node* mergeSort(Node* head) {
        Node *temp = head;
        vector<int> v;
        while(temp!=NULL){
            v.push_back(temp->data);
            temp = temp->next;
        }
        sort(v.begin(),v.end());
        temp = head;
        int i = 0;
        while(temp!=NULL && i<v.size()){
            temp->data = v[i];
            temp = temp->next;
            i++;
        }
        return head;
    }
};


