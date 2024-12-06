#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node * next;
};

void LinkedList(struct Node *ptr){
    while (ptr != NULL)
    {
        printf("Element %d\n",ptr->data);
        ptr = ptr -> next;
    }
}

//Case 1 Insert at first
struct Node * insirtAtFirst(struct Node * Head, int data){
    struct Node * ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->data = data;
    //ptr->data; // Access the `data` field of the structure `Node` pointed to by `ptr`
    //(*ptr).data; // Dereference the pointer `ptr` and then access the `data` field
    ptr->next = Head;

    return ptr;
}

//Case 2 Insert in between

struct Node * insirtinBetween(struct Node * Head, int data, int index){
    struct Node * ptr = (struct Node *)malloc(sizeof(struct Node));
    struct Node * p = Head;
    ptr->data = data;
    int i = 0;

    while (i != index-1 )
    {
       p = p->next;
       i++;
    }
    ptr->next = p->next;
    p->next = ptr;
    
    return Head;
}

//Case 3 Insert in the last
struct Node * insirtinTheLast(struct Node * Head, int data){
    struct Node * ptr = (struct Node *)malloc(sizeof(struct Node));
    struct Node * p = Head;
    ptr->data = data;

    
    while (p->next != NULL)
    {
        p = p -> next;
    }
    p->next = ptr;
    ptr->next = NULL ;

    return Head;
}

//Case 4 insert After Node
struct Node * insertAfterNode(struct Node* Head,struct Node * prevNode, int data){
    struct Node * ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->data = data;
    
    ptr->next = prevNode->next;
    prevNode->next = ptr;

    return Head;
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
    // Head = insirtAtFirst(Head,4);
    // Head = insirtinBetween(Head,4 ,3);
    // Head = insirtinTheLast(Head,4);
    Head = insertAfterNode(Head,Third,4);

    LinkedList(Head);
    return 0;
}