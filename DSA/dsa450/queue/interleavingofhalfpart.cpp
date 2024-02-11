#include <bits/stdc++.h> 
using namespace std;
void interLeaveQueue(queue < int > & q) {
    // Write your code here.
    int size = q.size()/2;
    queue<int> newq;
    for(int i =0;i<size;i++)
    {
        newq.push(q.front());
        q.pop();
    }
    while (!newq.empty())
    {
        q.push(newq.front());
        q.push(q.front());
        q.pop();
        newq.pop();
    }
}
int main()
{
    queue<int> q;
    q.push(32);
    q.push(1);
    q.push(2);
    q.push(3);
    interLeaveQueue(q);
    while(!q.empty())
    {
        cout<<q.front()<<endl;
        q.pop();
    }
}