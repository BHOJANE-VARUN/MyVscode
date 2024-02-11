#include<iostream>
#include<stack>
using namespace std;
void strrev(string& str)
{
    stack<char> sk;
    for(int i =0;i<str.length();i++)
    {
        sk.push(str[i]);
    }
    int i =0;
    while(!sk.empty())
    {
        str[i] = sk.top();
        i++;
        sk.pop();
    }
}
int main()
{
    string str = "varun";
    strrev(str);
    cout<<str<<endl;
}