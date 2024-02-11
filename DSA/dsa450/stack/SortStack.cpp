#include <bits/stdc++.h>
void solve(stack<int> &sk,int ele)
{
	if(sk.empty())
	{
		sk.push(ele);
		return;
	}
	if(sk.top()<=ele)
	{
		sk.push(ele);
		return;
	}

	int temp = sk.top();
	sk.pop();
	solve(sk,ele);
	sk.push(temp);
}
void sorting(stack<int> &stk)
{
	if(stk.empty())
	{
		return;
	}
	int ele = stk.top();
	stk.pop();
	sorting(stk);
	solve(stk  ,ele);
} 
void sortStack(stack<int> &stack)
{
	// Write your code here
	sorting(stack);
}