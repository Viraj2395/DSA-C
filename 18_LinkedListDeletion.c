#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

void linkedListTraversal(struct Node *ptr)
{
    while (ptr != NULL)
    {
        printf("Element %d\n", ptr->data);
        ptr = ptr->next;
    }
}

// Case 1: Deleting the first node.
struct Node *DeleteFirstNode(struct Node *Head, int data)
{
    struct Node *ptr = Head;
    ptr->data = data;

    Head = Head->next;

    free(ptr);
    return Head;
}

// Case 2: Deleting the node at the index.
struct Node *DelteatIndex(struct Node *Head, int index)
{
    struct Node *p = Head;
    struct Node *q = Head->next;

    for (int i = 0; i < index - 1; i++)
    {
        p = p->next;
        q = q->next;
    }

    p->next = q->next;
    free(q);
}

// Case 3: Deleting the last node.
struct Node *DeleteLastNode(struct Node *Head)
{
    struct Node *p = Head;
    struct Node *q = Head->next;

    while (q->next != NULL)
    {
        p = p->next;
        q = q->next;
    }

    p->next = NULL;
    free(q);
    return Head;
}

// Case 4: Deleting the first node with a given value.
struct Node *deleteAtIndex(struct Node *Head, int value)
{
    struct Node *p = Head;
    struct Node *q = Head->next;
    while (q->data != value && q->next != NULL)
    {
        p = p->next;
        q = q->next;
    }

    if (q->data == value)
    {
        p->next = q->next;
        free(q);
    }
    return Head;
}
int main()
{
    struct Node *Head;
    struct Node *second;
    struct Node *third;
    struct Node *fourth;

    Head = (struct Node *)malloc(sizeof(struct Node));
    second = (struct Node *)malloc(sizeof(struct Node));
    third = (struct Node *)malloc(sizeof(struct Node));
    fourth = (struct Node *)malloc(sizeof(struct Node));

    Head->data = 12;
    Head->next = second;

    second->data = 13;
    second->next = third;

    third->data = 14;
    third->next = fourth;

    fourth->data = 15;
    fourth->next = NULL;

    printf("Before Deletion the Linked List\n");
    linkedListTraversal(Head);
    printf("\nAfter Deletion the Linked List\n");
    // Head = DeleteFirstNode(Head, 12);
    // Head = DeleteAtIndex(Head, 2);
    // Head = DeleteLastNode(Head, 12);
    Head = deleteAtIndex(Head, 14);

    linkedListTraversal(Head);

    return 0;
}
/*
Consider a linked list: 11 -> 12 -> 13 -> 14 (Head points to 11)
If DeleteAtIndex(Head, 2) is called:

p starts at 11 and q at 12.
The loop runs once (as index - 1 = 2 - 1 = 1), updating p = 12 and q = 13.
The link is updated so p->next (12->next) now points to q->next (14), skipping 13.
Memory for q (node 13) is freed.
Resulting linked list: 11 -> 12 -> 14
*/