#include<stdio.h>
int stack[20];
int top = -1;
int push(int n)
{
    stack[++top]=n;
}
int pop()
{
    top--;
}
void decimaltobinary(int dec)
{
    while (dec>0)
    {
        push(dec%2);
        dec = dec/2;
    }
    int num = top;
    for (int i = num; i >=0; i--)
    {
        printf("%d ",stack[top]);
        pop();
    }
    
    
}
int main()
{
    printf("enter the number:");
    int num;
    scanf("%d",&num);
    decimaltobinary(num);
}