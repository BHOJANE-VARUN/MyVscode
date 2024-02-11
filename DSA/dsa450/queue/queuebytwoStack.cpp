#include <bits/stdc++.h> 
using namespace std;
class Queue{
    // Stacks to be used in the operations.
    stack<int> stk1, stk2;
    
    public:
    // Enqueues 'X' into the queue. Returns true after enqueuing.
    int solve(stack<int> &sk)
    {
        if(sk.empty())
        {
            return -1;
        }
        if(sk.size()==1)
        {   
            int ele = sk.top();
            sk.pop();
            return ele;
        }

        int ele = sk.top();
        sk.pop();
        int ans = solve(sk);
        sk.push(ele);
        return ans;
    }
    bool enqueue(int X){
        // Write your code here.
        if(!stk1.empty())
        {
            stk1.push(X);
            return true;
        }
        else{
            stk2.push(X);
            return true;
        }
    }

    /*
      Dequeues top element from queue. Returns -1 if the queue is empty, 
      otherwise returns the popped element.
    */
    int dequeue(){
        // Write your code here.
        if(stk1.empty() && stk2.empty())
        {
            return -1;
        }
        else if(!stk1.empty())
        {
            return solve(stk1);
        }
        else{
            return solve(stk2);
        }
    }
};
int main()
{
    
}