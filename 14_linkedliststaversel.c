#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

void LinkedList(struct Node *ptr){
    while (ptr != NULL)
    {
        printf("Element %d\n",ptr->data);
        ptr = ptr -> next;
    }
}

int main(){
    struct Node *Head;
    struct Node *Second;
    struct Node *Third;
    struct Node *Fourth;

    Head = (struct Node *)malloc(sizeof(struct Node));
    Second = (struct Node *)malloc(sizeof(struct Node));
    Third = (struct Node *)malloc(sizeof(struct Node));
    Fourth = (struct Node *)malloc(sizeof(struct Node));

    Head->data =11;
    Head->next = Second;
   
    Second->data =12;
    Second->next = Third;
   
    Third->data =13;
    Third->next = Fourth;
    
    Fourth->data =14;
    Fourth->next = NULL;

    LinkedList(Head);

    return 0;
}