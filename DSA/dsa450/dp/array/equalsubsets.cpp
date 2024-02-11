#include <bits/stdc++.h>
using namespace std; 
bool solve(vector<int> &arr,int n,int index,int l,int r)
{
    if(index==n && l==r)
    {
        return true;
    }
    if(index==n)return false;

    return solve(arr,n,index+1,l+arr[index],r) || solve(arr,n,index+1,l,r+arr[index]);
}
bool solvemem(vector<int> &arr,int n,int index,int l,int r,vector<vector<bool>> &dp)
{
    if(index==n && l==r)
    {
        return true;
    }
    if(index==n)return false;

   dp[l][r]  = solvemem(arr,n,index+1,l+arr[index],r,dp) || solvemem(arr,n,index+1,l,r+arr[index],dp);
   return dp[l][r];
}
//half range approach
bool subsetSumToK(int n, int k, vector<int> &arr)
{
    sort(arr.begin(), arr.end());

    int i = 0, ans = 0, j = 0;
    while (i<n)
    {
        if (ans < k)
        {
            ans += arr[i++];
        }
        else if (ans > k)
        {
            ans -= arr[j++];
        }
        if(ans == k)
        {
            return true;
        }
    }
    return false;
}
bool canPartition(vector<int> &arr, int n)
{   int range = accumulate(arr.begin(),arr.end(),0);
if(range%2)return false;

    // vector<vector<bool>> dp(range+1,vector<bool> (range+1,true));
    // return solvemem(arr,n,0,0,0,dp);
	//return solve(arr,n,0,0,0);
    return subsetSumToK(n,range/2,arr);
}
#include <bits/stdc++.h>
using namespace std; 
bool subsetSumToK(int n, int k, vector<int> &arr,vector<vector<int>> &dp)
{   if(k==0) return true;
    if(k<0) return false;
    if(n==-1) return false;
    if(dp[n][k]!=-1)return dp[n][k];

   bool inl = subsetSumToK(n-1, k-arr[n], arr,dp);
   bool excl =  subsetSumToK(n-1, k,arr,dp);
    dp[n][k]= inl or excl;
    return dp[n][k];
}
bool table(int n,vector<int> &arr)
{
    int range = accumulate(arr.begin(),arr.end(),0);
    if(range%2)return false;
    vector<vector<int>> dp(n+1,vector<int>((range/2)+1,0));
    for(int z =0;z<=n;z++)
    {
        dp[z][0] = 1;
    }
    for(int i=n-1;i>=0;i--)
    {
        for(int j =0;j<=range/2;j++)
        {  bool inl=0;
             if(j-arr[i]>=0)
             inl = dp[i+1][j-arr[i]];
            bool excl = dp[i+1][j];
            dp[i][j]= inl or excl;
            
        }
    }
    return dp[0][range/2];
}
bool canPartition(vector<int> &arr, int n)
{
    return table(n,arr);
}
// {   int range = accumulate(arr.begin(),arr.end(),0);
// if(range%2)return false;

//     // vector<vector<bool>> dp(range+1,vector<bool> (range+1,true));
//     // return solvemem(arr,n,0,0,0,dp);
// 	//return solve(arr,n,0,0,0);
//     vector<vector<int>> dp(n,vector<int>((range/2)+1,-1));
//     return subsetSumToK(n-1,range/2,arr,dp);
// }

int main()
{//20
//80 78 64 88 37 45 92 47 40 27 13 42 30 36 41 28 72 38 99 69
    vector<int> vec = {1 ,1 ,3 ,4 ,7};
    cout<<canPartition(vec,5);
}
