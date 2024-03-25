#include <stdio.h>
#include <stdbool.h>

// Definition for singly-linked list.
struct ListNode {
    int val;
    struct ListNode *next;
};

bool hasCycle(struct ListNode *head) {
    if (head == NULL || head->next == NULL) {
        return false; // If the list is empty or has only one node, there can't be a cycle
    }

    struct ListNode *slow = head;
    struct ListNode *fast = head->next;

    while (fast != NULL && fast->next != NULL) {
        if (slow == fast) {
            return true; // If slow and fast pointers meet, there is a cycle
        }
        slow = slow->next; // Move slow pointer one step forward
        fast = fast->next->next; // Move fast pointer two steps forward
    }

    return false; // If fast pointer reaches the end of the list, there is no cycle
}

int main() {
    // Create a linked list with a cycle
    struct ListNode *head = (struct ListNode *)malloc(sizeof(struct ListNode));
    head->val = 1;
    head->next = NULL;

    struct ListNode *second = (struct ListNode *)malloc(sizeof(struct ListNode));
    second->val = 2;
    second->next = head; // Create a cycle pointing back to the head

    head->next = second;

    // Check if the linked list has a cycle
    if (hasCycle(head)) {
        printf("The linked list has a cycle.\n");
    } else {
        printf("The linked list does not have a cycle.\n");
    }

    // Free allocated memory
    free(head);
    free(second);

    return 0;
}
