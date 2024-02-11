#include <bits/stdc++.h> 
using namespace std;
class Stack
{
public:
    // Initialize your data structure.
    deque<int> q;
    int cur;
    Stack()
    {
        //donot know
        cur =-1;
    }

    // Pushes 'X' into the stack. Returns true if it gets pushed into the stack, and false otherwise.
    bool push(int x)
    {
        // Write your code here.
        q.push_back(x);
        cur++;
        return true;
    }

    // Pops top element from Stack. Returns -1 if the stack is empty, otherwise returns the popped element.
    int pop()
    {
        // Write your code here.
        if(!q.empty())
        {
            int ele = q.back();
            q.pop_back();
            cur--;
            return ele;
        }
        else
        {
            return -1;
        }
        
        
    }

    // Returns the topmost element of the stack. In case the stack is empty, it returns -1.
    int top()
    {
        // Write your code here.
       if(!q.empty())
        return q.back();
        else return -1;
    }

    // Returns true if the stack is empty, otherwise false.
    bool isEmpty()
    {
        // Write your code here.
        return q.empty();
    }

    // Returns the number of elements currently present in the stack.
    int size()
    {
        // Write your code here.
        return q.size();
    }
};
int main()
{
    return 9;
}