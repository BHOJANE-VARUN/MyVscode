#include <bits/stdc++.h>
using namespace std;
class NQueue
{
    int *arr, *next, *front, *rear;
    int cur;
public:
    // Initialize your data structure.
    
    NQueue(int n, int s)
    {
        // Write your code here.
        arr = new int[s];
        next = new int[s];
        front = new int[n];
        rear = new int[n];
        for (int i = 0; i < n; i++)
        {
            front[i] = -1;
            rear[i] = -1;
        }
        cur = 0;
        for(int i =0;i<s;i++) next[i] = i+1;
        next[s - 1] = -1;
    }

    // Enqueues 'X' into the Mth queue. Returns true if it gets pushed into the queue, and false otherwise.
    bool enqueue(int x, int m)
    {
        if (cur != -1)
        {
            int index= cur;
            cur = next[index];
            if(rear[m-1]==-1)
            {
                front[m-1] = index;
                rear[m-1] = index;
            } else {
                next[front[m - 1]] =index;
                front[m-1] = index;
            }
            next[index] = -1;
            arr[index] = x;
            return true;
        }
        else
        {
            return false;
        }
    }

    // Dequeues top element from Mth queue. Returns -1 if the queue is empty, otherwise returns the popped element.
    int dequeue(int m)
    {   
        if (rear[m - 1] == -1)
        {
            return -1;
        }
        else{
            if(rear[m-1]==-1)
            {
                return -1;
            }
            int index = rear[m-1];
            rear[m-1] = next[index];
            if(rear[m-1]==-1)
            {
                front[m-1]=-1;
            }
            next[index] = cur;
            cur = index;

            return arr[index];
        }
    }
};
int main()
{
    NQueue q(3,2);
    cout<<q.enqueue(3,1)<<endl;
    cout<<q.enqueue(2,1)<<endl;
    cout<<q.enqueue(5,2)<<endl;
    cout<<q.dequeue(1)<<endl;
    cout<<q.enqueue(4,1)<<endl;
}