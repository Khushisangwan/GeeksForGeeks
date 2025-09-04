#include <bits/stdc++.h>
using namespace std;
class Solution {
    public:
        Node *reverseKGroup(Node *head, int k) {
                // Function to reverse nodes in groups of k
                
                Node*temp=head;   // Pointer to traverse the list
                Node*temp2=head;  // Pointer to update node values
                
                // Traverse the entire linked list
                while(temp!=nullptr){
                        stack<int>st;  // Stack to store k node values for reversal
                        
                        // Push k node values into stack (or until end of list)
                        for(int i=1;i<=k;i++){
                                if(temp==nullptr){
                                        break;  // Break if we reach end before k nodes
                                }
                                st.push(temp->data);  // Push current node's data
                                temp=temp->next;      // Move to next node
                        }
                        
                        // Pop from stack and update nodes (reverses the order)
                        while(!st.empty()){
                                int val=st.top();    // Get top value from stack
                                st.pop();            // Remove top element
                                temp2->data=val;     // Update current node with reversed value
                                temp2=temp2->next;   // Move to next node to update
                        }
                }
                return head;  // Return the modified list head
        }
};
