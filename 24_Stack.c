#include <stdio.h>
#include <stdlib.h>

struct Stack
{
    int size;
    int top;
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

int main()
{
    struct Stack *s = (struct Stack *)malloc(sizeof(struct Stack)); // Allocate memory for the struct
    s->size = 80;
    s->top = -1;
    s->arr = (int*)malloc(s->size * sizeof(int)); //It has no error but still code is not working so I copied firstl ine of the main function from chatgpt

    // Pushing an element manually
    s->arr[0] = 4;
    s->top++;

    s->arr[1] = 23;
    s->top++;

    s->arr[2] = 46;
    s->top++;  

    s->arr[3] = 55;
    s->top++;
    

    if (isEmpty(s))
    {
        printf("Stack is Empty");
    }
    else
    {
        printf("Stack is Not empty");
    }

    // Free the allocated memory
    free(s->arr);
    free(s);

    return 0;
}
