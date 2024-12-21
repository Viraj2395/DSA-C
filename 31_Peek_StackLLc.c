#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node * next;
};

struct Node* top = NULL;

void LinkedListTraversal(struct Node * ptr){
    while (ptr != NULL)
    {
        printf("Element: %d\n",ptr->data);
        ptr = ptr->next;
    }  
}

int isEmpty(struct Node * top){
    if(top == NULL){
        return 1;
    }
    else{
        return 0;
    }
}

int isFull(struct Node * top){
    struct Node * p = (struct Node*)malloc(sizeof(struct Node));
    if(p == NULL){
        return 1;
    }
    else{
        return 0;
    }
}

struct Node * Push(struct Node * top, int x){
    if (isFull(top))
    {
        printf("Stack overflow\n");
    }
    else{
        struct Node * p = (struct Node*)malloc(sizeof(struct Node));
        p->data = x;
        p->next = top;
        top = p;
        return top;
    }
    
}

int Pop(struct Node * tp){
    if (isEmpty(tp))
    {
        printf("Stack Underflow\n");
    }
    else{
        struct Node * p = tp;
        top = tp->next;
        int x = p->data;
        free(p);
        return x;
        
        return x;
    }
    
}

int Peek(int pos){
   struct Node* ptr = top;
   for (int i = 0; (i < pos-1 && ptr != NULL); i++)
   {
    ptr = ptr->next;
   }
   if (ptr != NULL)
   {
    return ptr -> data;
   }
   else{
    return -1;
   }
}


int main(){
    top = Push(top, 28);
    top = Push(top, 18);
    top = Push(top, 15);
    top = Push(top, 7);

    LinkedListTraversal(top);

    for (int i = 1; i <= 4; i++)
    {
        printf("Value at position %d is : %d\n", i , Peek(i));
    }
    

    return 0;
}