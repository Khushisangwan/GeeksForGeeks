#include<bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int x) : data(x), next(NULL) {}
};

class Solution {
  public:
    // Helper function to reverse a linked list
    // Time: O(n), Space: O(1)
    Node* reverseList(Node* head) {
        Node* prev = NULL;
        Node* curr = head;
        while (curr != NULL) {
            Node* next = curr->next;  // Save next node
            curr->next = prev;         // Reverse the link
            prev = curr;               // Move prev forward
            curr = next;               // Move curr forward
        }
        return prev;  // New head of reversed list
    }

    // Check if a linked list is a palindrome
    // Time: O(n), Space: O(1)
    bool isPalindrome(Node *head) {
        if (head == NULL || head->next == NULL) return true;

        // Step 1: Find the middle using slow and fast pointers
        Node *slow = head;
        Node *fast = head;
        while (fast->next != NULL && fast->next->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }

        // Step 2: Reverse the second half starting after slow
        Node* secondHalf = reverseList(slow->next);
        
        // Step 3: Compare first half with reversed second half
        Node* firstHalf = head;
        Node* currSecond = secondHalf;
        bool isPalin = true;
        
        while (currSecond != NULL) {
            if (firstHalf->data != currSecond->data) {
                isPalin = false;
                break;
            }
            firstHalf = firstHalf->next;
            currSecond = currSecond->next;
        }

        return isPalin;
    }
};