#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node* next;
};

void LinkedList(struct Node * ptr){
    while (ptr != NULL)
    {
        printf("Element %d\n", ptr -> data);
        ptr = ptr -> next;
    }
    
}


int main(){

    struct Node * Head;
    struct Node * second;
    struct Node * third;
    struct Node * fourth;

    Head = (struct Node *)malloc(sizeof(struct Node));
    second = (struct Node *)malloc(sizeof(struct Node));
    third = (struct Node *)malloc(sizeof(struct Node));
    fourth = (struct Node *)malloc(sizeof(struct Node));

    Head ->data = 5;
    Head -> next = second;
    
    second ->data = 6;
    second -> next = third;

    third ->data = 57;
    third -> next = fourth;

    fourth ->data = 52;
    fourth -> next = NULL;

    LinkedList(Head);
    return 0;
}