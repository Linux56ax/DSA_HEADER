#include <stdio.h>
#define Max 2

//Structure defining 
typedef struct stack
{
   int ar[Max];
   int top; /* data */
} stack;

//Top of stack
void top(stack *s)
{
    s-> top=-1;
}

//s Empty Function
int isempty(stack *s)
{
    return s-> top==-1;
}

//Is Full Function 
int isfull(stack *s)
{
    return s-> top == Max-1;
}

//Peak
int peak(stack *s)
{   
    if (isempty(s))
    {
        printf("Stack is empty\n");
        return -1; // Return an invalid value or handle error appropriately
    }
    return(s->ar[s->top]);
}


//Push Function
void push(stack *s, int item)
{
    if (isfull(s))
        {
            printf("Full");
            return;
        }
    s->ar[++(s->top)]=item;
}


//Pop Function
int pop(stack *s)
{
    if(isempty(s))
        {
            printf("Empty");
            return 99999;
        }
    int n=s->ar[(s->top)--];
    return n;
}



//Is look
/*int islook(stack *s)
{
    while(!isempty(*s))
    {
        pop(*s);
    }
}*/

//Stack push elem
/*int ispush(stack *s)
{   
    int elem=0;
    while(!isfull)
    {
        scanf("%d",&elem);
        push(*s , elem);
    }
}*/

// Main Funmction 
int main()
{
    stack s;
    top(&s);
    printf("To push the element press 1\n and to Pop the element press 2\n and to see the peak of the stack press 3\n");
    int elem=0, choice=0;
    //Menu driven Program to push and pop elements
    set:
    printf("Enter your choice\n");
    scanf("%d",&choice);
    while(!isfull(&s)||1)
    {
        switch(choice)
        {
            case 1:
            {
                printf("Enter the elemrnt to push\n");
                scanf("%d",&elem);
                push(&s,elem);
                printf("Element Pushed\n");
                goto set;
            }
            case 2:
                {
            if(isempty(&s))
                {
                    printf("Stack is empty\n");
                    goto set;
                }
            printf("The popped element is %d\n", pop(&s));
            goto set;
                }
            case 3:
            {
                printf("The top of the stack is %d\n", peak(&s));
                goto set;
            }
            default:
                {
            printf("Wrong Choice\n");
            goto set;
                }
        }
    }
    



}