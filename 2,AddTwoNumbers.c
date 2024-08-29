/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    struct ListNode dummy;       // Create a dummy node to act as the head of the result list
    struct ListNode* current = &dummy; // Pointer to the current node in the result list
    int carry = 0;               // Variable to store the carry value
    
    // Loop through both lists until both are fully traversed
    while (l1 != NULL || l2 != NULL) {
        int x = (l1 != NULL) ? l1->val : 0; // Get the value from l1, or 0 if l1 is NULL
        int y = (l2 != NULL) ? l2->val : 0; // Get the value from l2, or 0 if l2 is NULL
        int sum = carry + x + y;            // Calculate the sum of the values and the carry
        carry = sum / 10;                   // Update the carry for the next iteration
        current->next = (struct ListNode*)malloc(sizeof(struct ListNode)); // Allocate memory for a new node
        current->next->val = sum % 10;      // Assign the digit (sum % 10) to the new node
        current = current->next;            // Move to the next node in the result list
        
        // Move to the next nodes in l1 and l2, if available
        if (l1 != NULL) l1 = l1->next;
        if (l2 != NULL) l2 = l2->next;
    }
    
    // If there's a carry left after the last addition, add a new node with that carry value
    if (carry > 0) {
        current->next = (struct ListNode*)malloc(sizeof(struct ListNode));
        current->next->val = carry;
        current = current->next;
    }
    
    current->next = NULL; // Ensure the last node points to NULL
    return dummy.next; // Return the head of the result list (skipping the dummy node)
}
