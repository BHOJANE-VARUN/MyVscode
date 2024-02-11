#include<iostream>
#define size 5
using namespace std;
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
//circular queue

//double ended queue 

class doubleendedqueue{

int que[size];
int front =-1,rear =-1;
public:
void addtofront(int n)
{
    if ((rear==size-1 && front ==0) || ((rear+1)%size==front))
    {
       printf("\nque is full");
    }
    else if (rear == -1 && front ==-1)
    {
        rear =0;front =0;
        que[front]=n;
    }
    else if (front ==0)
    {
        front = size-1;
        que[front]=n;
    }
    
    else
    {
        front--;
        que[front]=n;
    }
    
    
}
void addtorear(int n )
{
    if ((rear==size-1 && front ==0) || ((rear+1)%size==front))
    {
       printf("\nque is full");
    }
    else if (rear == -1 && front ==-1)
    {
        rear =0;front =0;
        que[rear]==n;
    }
    else if (rear==size-1)
    {
        rear=0;
        que[rear]=n;
    }
    
    else
    {
        rear++;
        que[rear]=n;
    }
    
    
}
void removefromfront()
{
    if (rear ==-1 && front ==-1)
    {
        printf("\nque is empty");
    }
    else if (rear == front )
    {
        printf("\n%d is removed from front ",que[front]);
        front =-1,rear =-1;
    }
    else if (front==size-1)
    {
        front = 0;
    }
    
    else
    {   printf("\n%d is removed from front ",que[front]);
        front++;
    }
    
    
    
}
void removefromrear( )
{
    if (rear ==-1 && front ==-1)
    {
        printf("\nque is empty");
    }
    else if (rear == front )
    {
        printf("\n%d is removed from front ",que[rear]);
        front =-1,rear =-1;
    }
    else if (rear==0)
    {
        rear=size-1;
        
    }
    
    else
    {   printf("\n%d is removed from front ",que[rear]);
        rear--;
    }
    
    
    
}
void display()
{
    if (rear ==-1 && front ==-1)
    {
        printf("\nque is empty");
    }
    else{
        for (int i = front; i !=rear; i = (i+1)%size)
        {
           printf("%d   ",que[i]);
        }
        printf("%d",que[rear]);
        
    }
}
};
int main()
{
    return 0;
}

