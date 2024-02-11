#include <bits/stdc++.h> 
/*
	This is signature of helper function 'knows'.
	You should not implement it, or speculate about its implementation.

	bool knows(int A, int B); 
	Function 'knows(A, B)' will returns "true" if the person having
	id 'A' know the person having id 'B' in the party, "false" otherwise.
*/

int findCelebrity(int n) {
 	// Write your code here.
	stack<int> sk;
	for(int i =0;i<n;i++)
	{
		sk.push(i);
	}
	while(sk.size()>1)
	{
		int a = sk.top();
		sk.pop();
		int b = sk.top();
		sk.pop();
		if(knows(a,b))
		{
			sk.push(b);
		}
		else{
			sk.push(a);
		}
	}
	int ele = sk.top();
	bool flag = true;
	for(int i =0;i<n;i++)
	{	
		if(i==ele)
		{
			continue;
		}
		else{
			if(!knows(i,ele))
			{
				flag =0;
				break;
			}
		}
	}
	for(int i =0;i<n;i++)
	{	
		if(i==ele)
		{
			continue;
		}
		else{
			if(knows(ele,i))
			{
				flag =0;
				break;
			}
		}
	}
	if(flag==0)
	{
		return -1;
	}
	else{
		return ele;
	}
}