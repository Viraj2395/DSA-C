#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node* prev;
    struct Node* next;
};

void LinkedList(struct Node *ptr){
    while (ptr != NULL)
    {
        printf("Element %d\n",ptr->data);
        ptr = ptr -> next;
    }
}

void LinkedListRev(struct Node *ptr){
    while (ptr != NULL)
    {
        printf("Element %d\n",ptr->data);
        ptr = ptr -> prev;
    }
}

int main(){
    struct Node* Head;
    struct Node* Second;
    struct Node* Third;
    struct Node* Fourth;

    Head = (struct Node*)malloc(sizeof(struct Node));
    Second = (struct Node*)malloc(sizeof(struct Node));
    Third = (struct Node*)malloc(sizeof(struct Node));
    Fourth = (struct Node*)malloc(sizeof(struct Node));

    Head->data = 21;
    Head->prev = NULL;
    Head->next = Second;

    Second->data = 22;
    Second->prev = Head;
    Second->next = Third;

    Third->data = 23;
    Third->prev = Second;
    Third->next = Fourth;

    Fourth->data = 24;
    Fourth->prev = Third;
    Fourth->next = NULL;

    printf("Forward traversal:\n");
    LinkedList(Head);

    // Move to the last node for reverse traversal
    struct Node* Last = Fourth;

    printf("\nReverse traversal:\n");
    LinkedListRev(Last);

    // Free allocated memory
    free(Head);
    free(Second);
    free(Third);
    free(Fourth);
    return 0;
}