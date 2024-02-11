void solvebottom(stack<int>&sk,int x)
{
    if(sk.empty())
    {
        sk.push(x);
        return;
    }
    int ele = sk.top();
    sk.pop();
    solvebottom(sk,x);
    sk.push(ele);
}
void solve(stack<int>& sk)
{   
    if(sk.empty())
    {
        return;
    }
    int ele = sk.top();
    sk.pop();
    solve(sk);
    solvebottom(sk, ele);
}
void reverseStack(stack<int> &stack) {
    // Write your code here
    solve(stack);
}