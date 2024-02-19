#include<stdio.h>
#define size 5
int stack[size];
int top = -1;
void isempty()
{
    if (top==-1)
    {
            printf("\nstack is empty");
    }
    else{
        printf("\nstack is not empty");
    }
    
}
void push(int n )
{
    if(top==size-1)
    {
        printf("\nstack overflow condition");
    }
    else{
        top++;
        stack[top]=n;
    }
}
void pop()
{
    if (top==-1)
    {
        printf("\nunderflow condition");
    }
    else
    {   
        printf("\n%d is popped",stack[top]);
        top--;
    }
    
}
void main()
{
    push(5);
    push(4);
    push(7);
    push(2);
    push(9);
    push(5);
    pop(5);
    pop(4);
    pop(7);
    pop(2);
    pop(9);
    pop(5);
    isempty();
    
}