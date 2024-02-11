#include <iostream>
using namespace std;
class mystack
{
    int arr[100];
    int top;
    int size;

public:
    mystack(int x)
    {
        top = -1;
        size = x;
    }
    void getindex()
    {
        cout<<top<<endl;
    }
    void ifful()
    {
        if(top == size)
        {
            cout<<"stack is full"<<endl;
        }
        else{
            cout<<"stack is not full"<<endl;
        }
    }
    void push(int data)
    {
        if (top == size-1)
        {
            cout << "stack is full" << endl;
        }
        else
        {
            top++;
            arr[top] = data;
        }
    }
    bool empty()
    {
        if (top == -1)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    int pop()
    {
        if (top == -1)
        {
            cout << "stack is empty" << endl;
            return -1;
        }
        else
        {
            int ele = arr[top];
            top--;
            return ele;
        }
    }
    void peek()
    {
        if (top == -1)
        {
            cout << "stack is empty" << endl;
        }
        else
        {
            cout << arr[top] << endl;
        }
    }
};
int main()
{
    mystack sk(10);
    for (int i = 0; i < 11; i++)
    {
        sk.push(i);
    }
    sk.getindex();
    while(!sk.empty())
    {
        sk.peek();
        sk.pop();
    }
}