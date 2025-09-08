
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
                // Initialize a temporary pointer to traverse the linked list
                Node *temp = head;
                
                // Vector to store all the data values from the linked list
                vector<int> v;
                
                // Traverse the linked list and copy all data values to the vector
                while(temp != NULL){
                        v.push_back(temp->data);
                        temp = temp->next;
                }
                
                // Sort the vector using STL sort function
                sort(v.begin(), v.end());
                
                // Reset temp pointer to head for second traversal
                temp = head;
                int i = 0;
                
                // Traverse the linked list again and update node values with sorted data
                while(temp != NULL && i < v.size()){
                        temp->data = v[i];
                        temp = temp->next;
                        i++;
                }
                
                // Return the head of the modified linked list
                return head;
        }
};


