#include <stdio.h>
#include <stdlib.h>

struct Stack
{
    int size;
    int top;
    char *arr;
};

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

void Push(struct Stack *ptr, int x)
{
    if (isFull(ptr))
    {
        printf("Stack overflow\n");
    }
    else
    {
        ptr->top++;
        ptr->arr[ptr->top] = x;
    }
}

char Pop(struct Stack *ptr)
{
    if (isEmpty(ptr))
    {
        printf("Stack underflow and cannot pop an element");
        return -1;
    }
    else
    {
        char val = ptr->arr[ptr->top];
        ptr->top--;
        return val;
    }
}

int ParenthesisMatch(char *exp)
{
    
    struct Stack *sp = (struct Stack *)malloc(sizeof(struct Stack));
    sp->size = 100;
    sp->top = -1;
    sp->arr = (char *)malloc(sp->size * sizeof(char));

    for (int i = 0; exp[i] != '\0'; i++)
    {
        if (exp[i] == '(')
        {
            Push(sp, '(');
        }
        else if (exp[i] == ')')
        {
            if (isEmpty(sp))
            {
                return 0;
            }
            Pop(sp);
        }
    }

    if (isEmpty(sp))
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
    char * exp = "((8)(*--$$9))";
    
    if(ParenthesisMatch(exp)){
        printf("The parenthesis is Balanced");
    }
    else{
        printf("The parenthesis is not Balanced");
    }
    return 0;
}