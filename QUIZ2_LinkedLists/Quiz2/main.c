#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// Defining singly-linked list.
struct ListNode {
    int val;
    struct ListNode *next;
};

// Function to detect the starting node of the cycle
struct ListNode *detectCycle(struct ListNode *head) {
    if (head == NULL || head->next == NULL) {
        return NULL;
    }

    struct ListNode *slow = head;
    struct ListNode *fast = head;

    // Move slow pointer by one step and fast pointer by two steps
    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;

        // If they meet, there's a cycle
        if (slow == fast) {
            // Reset one pointer to the head
            slow = head;
            while (slow != fast) {
                slow = slow->next;
                fast = fast->next;
            }
            return slow; // Return the starting node of the cycle
        }
    }

    return NULL; // No cycle found
}

// Helper function to create a linked list node
struct ListNode *createNode(int val) {
    struct ListNode *node = (struct ListNode *)malloc(sizeof(struct ListNode));
    node->val = val;
    node->next = NULL;
    return node;
}

int main() {
    // creating a demo
    struct ListNode *head = createNode(1);
    head->next = createNode(2);
    head->next->next = createNode(3);
    head->next->next->next = createNode(4);
    head->next->next->next->next = head->next; // Create a cycle

    // Detect the starting node of the cycle
    struct ListNode *cycleStart = detectCycle(head);

    if (cycleStart) {
        printf("Cycle starts at node with value %d\n", cycleStart->val);
    } else {
        printf("No cycle found in the linked list.\n");
    }

    // Memory clean up
    free(head->next->next->next);
    free(head->next->next);
    free(head->next);
    free(head);

    return 0;
}
