#include<stdio.h>
#define size 5
int queue[size];
int front =-1,rear=-1;
void enqueue(int n)
{
    if ((rear+1)%size==front)
    {
        printf("\nqueue is full");
    }
    else if (rear==-1 && front ==-1)
    {
        rear =0;
        front =0;
        queue[rear]=n;
    }
    else{
        rear = (rear+1)%size;
        queue[rear]=n;
    }
    
    
}
void dequeue()
{
    if (rear==-1 && front ==-1)
    {
        printf("\nqueue is empty");
    }
    else if (rear==front)
    {
        printf("\n%d is dequeued",queue[front]);
        rear =-1;
        front =-1;
    }
    else
    {    printf("\n%d is dequeued",queue[front]);
        front = (front +1)%size;
    }
    
    
}
void display()
{
    if (rear ==-1 && front ==-1)
    {
            printf("\nqueue is empty");
    }
    else{
        for (int i = front;i!=rear+1;i=i+1%size)
        {
            printf("%d   ",queue[i]);
        }
        
    }
    
    
}
void isempty()
{
    if (rear==-1 && front ==-1)
    {
        printf("queue is empty");
    }
    else
    {
        printf("queue is not empty");
    }
    
    
}
int main()
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