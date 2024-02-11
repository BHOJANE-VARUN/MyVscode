#include<iostream>
#include<vector>
using namespace std;
int fibonormal(int n)
{
    if(n==1 || n==0)
    {
        return n;
    }
    return fibonormal(n-1) + fibonormal(n-2);
}
int fibodptopdown(int n,vector<int> &dp)
{
    if(n==1 || n==0)
    {
        return n;
    }
    //if answer is precalcuted then return it
    if(dp[n]!=-1)
    {
        return dp[n];
    }

    dp[n]= fibodptopdown(n-1,dp) + fibodptopdown(n-2,dp);
    return dp[n];
}
int main()
{   int n;
    cin>>n;
    cout<<"\n"<<fibonormal(n);
    //top down dp approch
    vector<int> dptd(n+1,-1);
    cout<<"\n"<<fibodptopdown(n,dptd);
    // bottom up and tabular approach 
    vector<int> dp;
    dp.push_back(0);
    dp.push_back(1);
    // dp[0]=0 dp[1]=1
    for (int i = 2; i < n+1; i++)
    {
       dp[i] = dp[i-1] + dp[i-2];
    }
    cout<<"\n"<<dp[n];
    // space optimaization (completely question depentent)
    // if we see that answer only depent on last two values 
    int pre1 = 0;
    int pre2 = 1;
    for (int i = 2; i < n+1; i++)
    {   int ans;
       ans = pre2 + pre1;
       pre1 = pre2;
       pre2 = ans;   
    }
    cout<<"\n"<<(n==0?0:pre2);

}