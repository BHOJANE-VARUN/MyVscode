#include<stdio.h>
#define size 5
int queue[size];
int rear =-1,front =-1;
void enqueue(int n)
{
    if (rear==size-1)
    {
        printf("\nqueue is full");
    }
    else
    {
        rear++;
        queue[rear]=n;
    }
    
    
}
void dequeue()
{
    if (front==rear)
    {
        printf("\nqueue is empty");

    }
    else
    {
        front++;

       printf("\n%d is dequeued", queue[front]);
       if (front==size-1)
       {
        front =-1;
        rear =-1;
       }
       
    }
    
    
}
void display()
{
    if (rear==front)
    {
        printf("\nqueue is empty");
    }
    else
    {
        for (int i = front +1; i <=rear; i++)
        {
           printf("%d  ",queue[i]);
        }
        
    }
    
    
}
void isempty()
{
    if (rear==front)
    {
        printf("\nqueue is empty");
    }
    
}
void main()
{
    enqueue(34);
    enqueue(3);
    enqueue(4);
    enqueue(35);
    enqueue(5);
    display();
    dequeue();
    dequeue();
    dequeue();
    dequeue();
    dequeue();
    isempty();


}