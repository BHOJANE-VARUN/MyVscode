#include "stack"
vector<int> nextSmallerElement(vector<int> &arr, int n)
{
    // Write your code here.
    stack<int> sk;
    sk.push(-1);
    for(int i =n-1;i>=0;i--)
    {   int ele = arr[i];
        while(sk.top()>=ele && (!sk.empty()))
        {
            sk.pop();
        }
        arr[i] = sk.top();
        sk.push(ele);
    }
    return arr;
}