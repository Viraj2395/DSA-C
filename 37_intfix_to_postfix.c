#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Stack
{
    int top;
    int size;
    char *arr;
};

int stackTop(struct Stack *sp)
{
    return sp->arr[sp->top];
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

void push(struct Stack *ptr, int x)
{
    if (isFull(ptr))
    {
        printf("Stack overflow");
    }
    else
    {
        ptr->top++;
        ptr->arr[ptr->top] = x;
    }
}

char pop(struct Stack *ptr)
{
    if (isEmpty(ptr))
    {
        printf("Stac Underflow");
        return -1;
    }
    else
    {
        char val = ptr->arr[ptr->top];
        ptr->top--;
        return val;
    }
}

int isPrecedence(char ch){
    if (ch == '*' || ch == '/')
    {
        return 3;
    }
    else if (ch == '+' || ch == '-')
    {
        return 2;
    }
    else
    return 0;
} 

int isOperator(char ch){
    if (ch == '*' || ch == '/' || ch == '+' || ch == '-')
    {
        return 1;
    }
    else{
        return 0;
    }
}

char *infixToPostfix(char *infix)
{
    struct Stack *sp = (struct Stack *)malloc(sizeof(struct Stack));
    sp->size = 100;
    sp->top = -1;
    sp->arr = (char *)malloc(sp->size * sizeof(char));
    char *postfix = (char *)malloc((strlen(infix) + 1) * sizeof(char));
    int i = 0; // Track infix traversal
    int j = 0; // Track postfix addition

    while (infix[i] != '\0')
    {
        if (!isOperator(infix[i]))
        {
            postfix[j] = infix[i];
            i++;
            j++;
        }
        else
        {
            if (isPrecedence(infix[i]) > isPrecedence(stackTop(sp)))
            {
                push(sp, infix[i]);
                i++;
            }
            else
            {
                postfix[j] = pop(sp);
                j++;
            }
        }
    }
    while (!isEmpty(sp))
    {
        postfix[j] = pop(sp);
        j++;
    }
    postfix[j] = '\0';
    return postfix;
}

int main()
{
    char *infix = "x-d";
    printf("postfix is %s", infixToPostfix(infix));
    return 0;
}