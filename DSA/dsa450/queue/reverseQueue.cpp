#include <bits/stdc++.h> 
using namespace std;
void reverse(queue<int> &q)
{
    // Write your code here.
    stack<int> sk;
    while(!q.empty())
    {
        sk.push(q.front());
        q.pop();
    }
    while(!sk.empty())
    {
        q.push(sk.top());
        sk.pop();
    }
    
}
int main()
{
    queue<int> sk;
    sk.push(23);
    sk.push(56);
    sk.push(68);
    reverse(sk);
    
}