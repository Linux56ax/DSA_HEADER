#include <stdio.h>
#include <stdlib.h> // For malloc and free
#define Max 2

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

// Main Function 
int main()
{
    stack s;
    int capacity = Max;
    init_stack(&s, capacity);

    printf("To push the element press 1\nTo Pop the element press 2\nTo see the peak of the stack press 3\n");
    int elem = 0, choice = 0;
set:
    printf("Enter your choice\n");
    scanf("%d", &choice);
    while (1)
    {
        switch (choice)
        {
            case 1:
                printf("Enter the element to push\n");
                scanf("%d", &elem);
                push(&s, elem);
                printf("Element Pushed\n");
                goto set;
            case 2:
                if (isempty(&s))
                {
                    printf("Stack is empty\n");
                    goto set;
                }
                printf("The popped element is %d\n", pop(&s));
                goto set;
            case 3:
                printf("The top of the stack is %d\n", peak(&s));
                goto set;
            default:
                printf("Wrong Choice\n");
                goto set;
        }
    }

    free_stack(&s);
    return 0;
}