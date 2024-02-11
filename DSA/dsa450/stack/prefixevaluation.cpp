#include<iostream>
#include<stack>
using namespace std;
int evaluatePostfix(string &exp) {
    stack<int> sk;
    for(int i =0;i<exp.length();i++)
    {   if(exp[i]!=' ')
        {
        if('0'<= exp[i] && exp[i]<= '9')
        {
            sk.push(exp[i]);
        }
        else{
            int ele1 = sk.top();
            if(sk.top()>9)
             ele1 = sk.top()-((int)'0');
            sk.pop();
            int ele2 = sk.top();
            if(sk.top()>9)
            ele2 = sk.top()-((int)'0');
            sk.pop();
            if(exp[i]=='+')
            {
                sk.push(ele1+ele2);
            }
            else if(exp[i]=='-')
            {
                sk.push(ele2-ele1);
            }
            else if(exp[i]=='*')
            {
                sk.push(ele1*ele2);
            }
            else{
                sk.push(ele2/ele1);
            }
        }}
    }
    return sk.top();
}
int main()
{
    string str = "2 3 1 * + 9 -";
    cout<<evaluatePostfix(str);
}