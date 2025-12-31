class Solution {
  public:
    // Helper to reverse a list (cleaner implementation)
    Node* reverseList(Node* head) {
        Node* prev = NULL;
        Node* curr = head;
        while (curr != NULL) {
            Node* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }

    bool isPalindrome(Node *head) {
        if (head == NULL || head->next == NULL) return true;

        // Step 1: Find the middle of the linked list
        // 'slow' will end up at the middle node (or left-middle for even length)
        Node *slow = head;
        Node *fast = head;
        
        while (fast->next != NULL && fast->next->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }

        // Step 2: Reverse the second half of the list
        // We reverse everything AFTER the 'slow' node
        Node* secondHalf = reverseList(slow->next);
        
        // Step 3: Compare the first half and the reversed second half
        Node* firstHalf = head;
        Node* currSecond = secondHalf;
        bool isPalin = true;
        
        while (currSecond != NULL) {
            if (firstHalf->data != currSecond->data) {
                isPalin = false; // Mismatch found
                break;
            }
            firstHalf = firstHalf->next;
            currSecond = currSecond->next;
        }
        
        // Step 4 (Optional): Restore the list to original state
        // slow->next = reverseList(secondHalf);

        return isPalin;
    }
};