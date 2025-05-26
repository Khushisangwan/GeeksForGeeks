
#include<bits/stdc++.h>
using namespace std;
class Solution {
  public:
    Node* sortedInsert(Node* head, int data) {
        // code here
         Node* prev=head;
        Node* curr=head->next;
        while(curr!=head && curr->data<data){
            prev=prev->next;
            curr=curr->next;
        }
        Node* newNode=new Node(data);
        prev->next=newNode;
        newNode->next=curr;
        if(data<=head->data)
        swap(head->data,newNode->data);
        return head;
    }
};