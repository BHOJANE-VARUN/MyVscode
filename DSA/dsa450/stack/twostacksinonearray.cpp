#include <bits/stdc++.h> 
class TwoStack {

public:

    // Initialize TwoStack.
    int *arr;
    int top1,top2;
    int size;
    TwoStack(int s) {
        // Write your code here.
        this->size = s;
        top1 = -1;
        top2 = s;
        arr = new int[s];
    }
    
    // Push in stack 1.
    void push1(int num) {
        // Write your code here.
        if(top2-top1>1)
        {top1++;
        arr[top1]=num;}
    }

    // Push in stack 2.
    void push2(int num) {
        // Write your code here.
        if(top2-top1>1)
        {top2--;
        arr[top2] = num;}
    }

    // Pop from stack 1 and return popped element.
    int pop1() {
        // Write your code here.
        if(top1==-1)
        {
            return -1;
        }
        else{
            int ele = arr[top1];
            top1--;
            return ele;
        }
    }

    // Pop from stack 2 and return popped element.
    int pop2() {
        // Write your code here.
        if(top2==size)
        {
            return -1;
        }
        else{
            int ele = arr[top2];
            top2++;
            return ele;
        }
    }
};
