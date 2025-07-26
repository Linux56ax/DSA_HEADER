#include <stdio.h>
#include <stdlib.h> // For malloc and free
#define Max 2

#ifndef STACK_H
#define STACK_H

// Structure defining 
typedef struct stack
{
   int *ar;   // Change from int ar[Max]; to int *ar;
   int top;
   int capacity; // Store the capacity
} stack;

// Initialize stack
void init_stack(stack *s, int capacity)
{
    s->ar = (int *)malloc(capacity * sizeof(int));
    s->top = -1;
    s->capacity = capacity;
}

// Free stack memory
void free_stack(stack *s)
{
    free(s->ar);
}

// Is Empty Function
int isempty(stack *s)
{
    return s->top == -1;
}

// Is Full Function 
int isfull(stack *s)
{
    return s->top == s->capacity - 1;
}

// Peak
int peak(stack *s)
{   
    if (isempty(s))
    {
        printf("Stack is empty\n");
        return -1;
    }
    return s->ar[s->top];
}

// Push Function
void push(stack *s, int item)
{
    if (isfull(s))
    {
        printf("Full\n");
        return;
    }
    s->ar[++(s->top)] = item;
}

// Pop Function
int pop(stack *s)
{
    if (isempty(s))
    {
        printf("Empty\n");
        return 99999;
    }
    int n = s->ar[(s->top)--];
    return n;
}

#endif // STACK_H

