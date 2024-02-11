#include <bits/stdc++.h> 
void solve(stack<int>&input,int i,int size)
{
   if(i==(size-1)/2)
   {
      input.pop();
      return;
   }

   int ele = input.top();
   input.pop();
   solve(input,i+1,size);
   input.push(ele);
}
void deleteMiddle(stack<int>&inputStack, int N){
	
   // Write your code here
   solve(inputStack,0,inputStack.size());
}