#include <stdio.h>
#include <stdlib.h>

struct Stack{
    int top;
    int size;
    int *arr;
};

int isEmpty(struct Stack *ptr)
{
    if (ptr->top == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int isFull(struct Stack *ptr)
{
    if (ptr->top == ptr->size - 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void push(struct Stack *ptr, int val)
{
    if (isFull(ptr))
    {
        printf("Stack Overflow because val %d is extra element\n", val);
    }
    else
    {
        ptr->top++;
        ptr->arr[ptr->top] = val;
    }
}
int pop(struct Stack *ptr)
{
    if (isEmpty(ptr))
    {
        printf("Stack Underflow ");
        return -1;
    }
    else
    {
        int val = ptr->arr[ptr->top];
        ptr->top--;
        return val;
    }
}


int peek(struct Stack *sp,int i){
    int arrInd = sp->top-i+1; 
    if(arrInd < 0){
        printf("No valid postion\n");
        return -1;
    }
    else{
        return sp->arr[arrInd];
    }
}

int main(){
    struct Stack *sp = (struct Stack*)malloc(sizeof(struct Stack));
    sp->size = 15 ;
    sp->top = -1;
    sp->arr = (int *)malloc(sp->size* sizeof(int));

    push(sp, 45);
    push(sp, 45);
    push(sp, 17);
    push(sp, 69);
    push(sp, 1);
    push(sp, 97);
    push(sp, 12);
    push(sp, 64);
    push(sp, 23);
    push(sp, 4); 
    push(sp, 4); 

    for (int j = 1 ; j <= sp -> top + 1; j++)
    {
        printf("The value at position %d is %d\n",j , peek(sp,j));
    }
    
    return 0;
} 