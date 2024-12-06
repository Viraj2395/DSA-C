#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

void linkedListTraversal(struct Node* Head){
    struct Node * ptr = Head;
    do
    {
        printf("Element is %d\n",ptr->data);
        ptr = ptr->next;
    } while (ptr != Head); 
}

struct Node* insertAtFirst(struct Node* Head, int data){
    struct Node* ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->data = data; 

    struct Node* p = Head->next;

    while (p->next != Head)
    {
        p = p->next;
    }
    
    p->next = ptr;
    ptr->next = Head;
    Head = ptr;

    return Head;
}

int main()
{
    struct Node *Head;
    struct Node *Second;
    struct Node *Third;
    struct Node *Fourth;

    Head = (struct Node *)malloc(sizeof(struct Node));
    Second = (struct Node *)malloc(sizeof(struct Node));
    Third = (struct Node *)malloc(sizeof(struct Node));
    Fourth = (struct Node *)malloc(sizeof(struct Node));

    Head->data = 4;
    Head->next = Second;

    Second->data = 3;
    Second->next = Third;

    Third->data = 6;
    Third->next = Fourth;

    Fourth->data = 1;
    Fourth->next = Head;

    printf("Before insertion in the cicular Linked List\n");
    linkedListTraversal(Head);
    Head = insertAtFirst(Head,34);
    printf("\nAfter insertion in the cicular Linked List\n");
    linkedListTraversal(Head);

    return 0;
}