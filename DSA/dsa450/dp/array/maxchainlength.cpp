#include <bits/stdc++.h> 
using namespace std;
int solve(vector<vector<int>> &arr,int i,int ele)
{
	if(i==arr.size()) return 0;
    int firs = arr[i][0],sec = arr[i][1];
	if(ele<arr[i][0]) 
			{
				int incl = 1 + solve(arr,i+1,arr[i][1]);
				int exlc = solve(arr,i+1,ele);
				return max(incl,exlc);
			}
	else{
        ele = min(ele,arr[i][1]);
		return solve(arr,i+1,ele);
	}
	
}
int solve(vector<vector<int>> &arr,int i,int ele,vector<int> &dp)
{
	if(i==arr.size()) return 0;
	if(dp[i]!=-1) return dp[i];

	if(ele<arr[i][0]) 
	{
		int incl = 1 + solve(arr,i+1,arr[i][1],dp);
		int exlc = solve(arr,i+1,ele,dp);
		return dp[i] = max(incl,exlc);
	}
	else{
        ele = min(ele,arr[i][1]);
		return dp[i] =solve(arr,i+1,ele,dp);
	}
	
}
int getLongestChainLength(vector<vector<int>> &pairs)
{
	//    Write your code here.
	vector<int> dp(pairs.size()+1,-1);
	sort(pairs.begin(),pairs.end());
	return 1 + solve(pairs,1,pairs[0][1],dp);
}
int getLongestChainLength(vector<vector<int>> &pairs)
{
	//    Write your code here.
	sort(pairs.begin(),pairs.end());
	return 1 + solve(pairs,1,pairs[0][1]);
}
int main()
{
    vector<vector<int>> arr = {{4,8},{8 ,9},{2, 4},{1 ,9},{0, 10}};
    cout<<getLongestChainLength(arr);
}