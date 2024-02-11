#include <bits/stdc++.h> 
using namespace std;
int solve(int len,int a,int b,int c)
{
    if(len==0) return 0;
    if(len<0) return INT_MIN;

    int one = 1 + solve(len-a,a,b,c);
    int two = 1 + solve(len-b,a,b,c);
    int three = 1 + solve(len-c,a,b,c);
    return max(one,max(two,three));
}
int findMaxNumSegements(int len, int a,int b,int c){
    // Write your code here.
    if(len==0) return 0;
    if(len<0) return INT_MIN;

    int one = 1 + findMaxNumSegements(len-a,a,b,c);
    int two = 1 + findMaxNumSegements(len-b,a,b,c);
    int three = 1 + findMaxNumSegements(len-c,a,b,c);
    return max(one,max(two,three));
    
}
int main()
{
    cout<<findMaxNumSegements(4,2,1,3);
}