#include <stdio.h>
#include <stdlib.h>

struct Stack
{
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

int main()
{
    struct Stack *sp = (struct Stack *)malloc(sizeof(struct Stack));
    sp->size = 10;
    sp->top = -1;
    sp->arr = (int *)malloc(sp->size * sizeof(int));
    printf("The stack has been called\n");

    printf("Before calling the push Function the isFull is : %d\n", isFull(sp));
    printf("Before calling the push Function the isEmpty is : %d\n", isEmpty(sp));

    push(sp, 45);
    push(sp, 45);
    push(sp, 17);
    push(sp, 69);
    push(sp, 1);
    push(sp, 97);
    push(sp, 12);
    push(sp, 64);
    push(sp, 23);
    push(sp, 4); // --> Pushed 10 vlaues
    // push(sp,45);  // Stack overflow since the size of stack is 10

    printf("Before calling the push Function the isFull is : %d\n", isFull(sp));
    printf("Before calling the push Function the isEmpty is : %d\n", isEmpty(sp));

    printf("Popped %d from the stack\n", pop(sp));
    printf("Popped %d from the stack\n", pop(sp));
    printf("Popped %d from the stack\n", pop(sp));
    printf("Popped %d from the stack\n", pop(sp));
    printf("Popped %d from the stack\n", pop(sp));

    return 0;
}