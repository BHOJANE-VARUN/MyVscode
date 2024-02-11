#include<iostream>
#include<stack>
using namespace std;
int main()
{
    stack<int> sk;
    for(int i =0;i<5;i++)
    {
        sk.push(i);
    }
    cout<<sk.top()<<endl;
    cout<<sk.size()<<endl;
    while(!sk.empty())
    {
        cout<<sk.top()<<endl;
        sk.pop();
    }
}