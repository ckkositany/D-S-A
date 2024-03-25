#include <stdio.h>
#include <stdlib.h>

// Def for singly-linked list.
struct ListNode {
    int val;
    struct ListNode *next;
};

// Function to reverse a linked list
struct ListNode *reverseList(struct ListNode *head) {
    struct ListNode *prev = NULL;
    struct ListNode *current = head;
    struct ListNode *nextNode;

    while (current != NULL) {
        nextNode = current->next;
        current->next = prev;
        prev = current;
        current = nextNode;
    }

    return prev; // New head of the reversed list
}

// Helper function to create a new node
struct ListNode *createNode(int val) {
    struct ListNode *node = (struct ListNode *)malloc(sizeof(struct ListNode));
    node->val = val;
    node->next = NULL;
    return node;
}

// Helper function to print the linked list
void printList(struct ListNode *head) {
    struct ListNode *temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->val);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    // Create a sample linked list
    struct ListNode *head = createNode(1);
    head->next = createNode(2);
    head->next->next = createNode(3);
    head->next->next->next = createNode(4);
     head->next->next->next->next = createNode(5);

    printf("Original linked list:\n");
    printList(head);

    // Reverse the linked list
    struct ListNode *reversedHead = reverseList(head);

    printf("Reversed linked list:\n");
    printList(reversedHead);

    // Memory cleanup
    while (reversedHead != NULL) {
        struct ListNode *temp = reversedHead;
        reversedHead = reversedHead->next;
        free(temp);
    }

    return 0;
}
