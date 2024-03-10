#include<bits/stdc++.h>
#define int long long int
#define yes cout<<"YES"<<endl;
#define no cout<<"NO"<<endl
#define MOD 1000000007
//const int maxsize = 1e5;
//int arr[maxsize+1];
#define test int monu;cin>>monu;while(monu--)
using namespace std;
//what information is needed only any index 
//logically if at any index I put any value val-1,val,val+1 are only options for answer right 
int solve(int *arr,int ind,int n,int m,vector<vector<int>>&dp)
{
    if(ind==n)
    {
        return 1;
    }
    if(ind!=0 and dp[ind][arr[ind-1]]!=-1)
    {
        return dp[ind][arr[ind-1]];
    }
    if(arr[ind]!=0)
    {
        int ans = solve(arr,ind+1,n,m,dp)%MOD;
        for(int i =0;i<=m;i++) dp[ind][i] = ans;
        return ans;
    }
    int ans =0;
    for(int i =1;i<=m;i++)
    {
        if(ind==0)
        {   
            if(arr[ind+1]==0 or abs(arr[ind+1]-i)<2)
            {
                arr[ind]=i;
                ans = (ans + solve(arr,ind+1,n,m,dp))%MOD;
                arr[ind] =0;
            }
        }
        else if(ind==n-1)
        {
            if(abs(arr[ind-1]-i)<2)
            {
                arr[ind]=i;
                ans = (ans + solve(arr,ind+1,n,m,dp))%MOD;
                arr[ind] =0;
            }
        }
        else{
            if((arr[ind+1]==0 or abs(arr[ind+1]-i)<2) and abs(arr[ind-1]-i)<2)
            {
                arr[ind]=i;
                ans = (ans + solve(arr,ind+1,n,m,dp))%MOD;
                arr[ind] =0;
            }
        }
    }
    if(ind!=0)
    {
        dp[ind][arr[ind-1]] = ans;
    }
    return ans;
}
// so dp[i][k] tells us that prefix upto i i.e. if I include first i elements then I can have no. of distinct arrays if ith index have k element
// logically it restricts the previous element to be k-1,k,k+1 right
// so trasition will be dp[i][k] = dp[i-1][k-1]+dp[i-1][k]+dp[i-1][k+1]
// all of the above is for 0 but is element is other than 0 then
// 
// what is base case?
// as we continue restricts previous element and contiuously move backwards, at some point we left with one element
// so at i==0 element is 0 or it is that element which we want to put then it is a answer, therefore value will be 1 i.e ans++
// else it will be zero
// so at end dp[n][k] will tell us that no. of arrays can be constructed if we use all elements and last element is k 
// as we can put any element between 1 to m , last answer will be summation of all values dp[n][j] j from 1 to m
// donot get confuse by indexing of dp array and integers array , question array is zero-base index and dp array is 1-base indexe
int solveit(int *arr,int n,int m)
{
    vector<vector<int>> dp(n+2,vector<int>(m+2,0));
    for(int i =0;i<=m;i++)
    {
        if(arr[0]==i or arr[0]==0)
        {
            dp[1][i] = 1;
        }
    }
    for(int i = 2;i<=n;i++)
    {
        for(int j = 1;j<=m;j++)
        {
            if(arr[i-1]!=0 and arr[i-1]!=j)
            {
                dp[i][j] = 0;
            }
            else{
                for(int perv = max(1ll,j-1);perv <= min(m,j+1);perv++)
                {
                    dp[i][j] = (dp[i][j] + dp[i-1][perv])%MOD;
                }
            }
        }
    }
    int ans =0;
    for(int i =1;i<=m;i++) ans = (ans + dp[n][i])%MOD;
    return ans;
}
signed main()
{
    // int n,x;
    // cin>>n>>x;
    // int *arr = new int[n];
    // int f =1;
    // for(int i =0;i<n;i++)
    // {
    //   cin>>arr[i];
    //   if(arr[i]==0)
    //   {
    //     f=0;
    //   }
    //   if(i!=0)
    //   {
    //     if(arr[i]!=0 and arr[i-1]!=0)
    //     {
    //         if(abs(arr[i]-arr[i-1])>=2)
    //         {
    //             cout<<0<<endl;
    //             return 0;
    //         }
    //     }
    //   }
    // }
    // if(f)
    // {
    //     cout<<1<<endl;
    //     return 0;
    // }
    // if(n==1)
    // {
    //     cout<<x<<endl;
    //     return 0;
    // }
    int n,x;
    cin>>n>>x;
    int *arr = new int[n];
    for(int i =0;i<n;i++)
    {
      cin>>arr[i];
    }
    
    //at ith,1 to m which I select
    // vector<vector<int>> dp(n+1,vector<int>(x+2,-1));
    // cout<<solve(arr,0,n,x,dp)<<endl;
    cout<<solveit(arr,n,x)<<endl;
//dusro ka code copy karne se ghar nahi chalta bhai
}