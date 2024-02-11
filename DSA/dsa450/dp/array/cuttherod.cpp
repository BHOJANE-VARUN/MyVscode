#include <bits/stdc++.h>
using namespace std;
int solve(int n,vector<int> &vec,int index)
{
    if(n<0 || index>=3)return INT_MIN;
    if(n ==0 )return 0;
    //exclude
    int ex = solve(n,vec,index+1);
    //include
    int in = 1+solve(n-vec[index],vec,index);
    return max(ex,in);
}
int cutSegments(int n, int x, int y, int z) {
	// Write your code here.
	if(x==1 || y==1 || z ==1)return n;
    vector<int> vec = {x,y,z};
    return solve(n,vec,0);

}
int solve(int n,vector<int> &vec,vector<int> &dp)
{
    if(n<0)return INT_MIN;
    if(n ==0 )return 0;
    //exclude
    if(dp[n]!=-1)return dp[n];

    int ans1 =1 + solve(n-vec[0],vec,dp);
    int ans2 =1 + solve(n-vec[1],vec,dp);
    int ans3 =1+ solve(n-vec[2],vec,dp);

    dp[n]=max(ans1,max(ans2,ans3));
    return dp[n];
}
// int cutSegments(int n, int x, int y, int z) {
// 	// Write your code here.
// 	if(x==1 || y==1 || z ==1)return n;
//     vector<int> vec = {x,y,z};
//     vector<int> dp(n+1,-1);
// 	int ans =  solve(n,vec,dp);
// 	return ans<0?0:ans;

// }
int solvetabop(int n,int x,int y,int z)
{
	vector<int> dp(n+1,-1);
	dp[0]=0;
	for(int i =0;i<n+1;i++)
	{
		if(0<=i-x && dp[i-x]!=-1)
		{
			dp[i]=max(dp[i],1+dp[i-x]);
		}
		if(0<=i-y && dp[i-y]!=-1)
		{
			dp[i]=max(dp[i],1+dp[i-y]);
		}
		if(0<=i-z && dp[i-z]!=-1)
		{
			dp[i]=max(dp[i],1+dp[i-z]);
		}
	}
	return dp[n]==-1?0:dp[n];
}
int cutSegments(int n, int x, int y, int z) {
	// Write your code here.
	// bool flag = 0;
	// if (n <= 0)
	// 	return 0;
	// if (x == 1 or y == 1 or z == 1)
	// 	return n;
	// if (n == x or n == y or n == z)
	// 	flag = 1;
	// int ans = max(cutSegments(n-x,x,y,z),max(cutSegments(n-y,x,y,z),cutSegments(n-z,x,y,z))); 
	// if (ans == 0 and flag == 1)
	// 	return 1;
	// else if (ans == 0 and flag == 0)
	// 	return 0;
	// return 1+ans;
	return solvetabop(n, x, y, z);
}
int main()
{
    cout<<cutSegments(7,5,2,2);
}