#include <bits/stdc++.h> 
using namespace std;
void reverse(queue<int> &q,int k)
{
    // Write your code here.
    stack<int> sk;
    int i =0;
    while(i<k)
    {
        sk.push(q.front());
        q.pop();
        i++;
    }
    int j =0;
    vector<int> vec;
    while(!q.empty())
    {
        vec.push_back(q.front());
        q.pop();
        j++;
    }
    while(i>0)
    {
        q.push(sk.top());
        sk.pop();
        i--;
    }
    int size =0;
        while(size<vec.size())
    {
        q.push(vec[size]);
        size++;
    }
}
int main()
{
    queue<int> q;
    q.push(2);
    q.push(4);
    reverse(q,1);
    
}