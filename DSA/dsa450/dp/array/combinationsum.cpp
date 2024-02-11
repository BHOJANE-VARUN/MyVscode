#include <bits/stdc++.h>
using namespace std;
void solve(vector<int> &nums, int tar, int &ans)
{
    if ( 0 > tar)
    {
        return;
    }

    if (tar == 0)
    {
        ans++;
        return;
    }
    for (auto i : nums)
    { // include
        solve(nums, tar - i, ans);
    }
}
int  solvemem(vector<int> &nums, int tar,vector<int> &dp)
{
    if ( 0 > tar)
    {
        return 0;
    }

    if (tar == 0)
    {
        return 1;
    }

    if(dp[tar]!=-1)return dp[tar];

    int ans =0;
    for (auto i : nums)
    { // include
       ans += solvemem(nums, tar - i,dp);
    }
    dp[tar] = ans;
    return dp[tar];
}
int table(vector<int> &num,int tar)
{
    vector<int> dp(tar+1,0);
    //base cases
    dp[0]=1;
    for(int i =1;i<=tar;i++)
    {
        for(int j =0;j<num.size();j++)
        {   if(0<=i-num[j])
            dp[i] += dp[i-num[j]];
        }
    }
    return dp[tar];
}
int findWays(vector<int> &num, int tar)
{
    // Write your code here.
    // int ans = 0;
    // solve(num, tar, ans);
    // return ans;
    // vector<int> dp(tar+1,-1);
    // return solvemem(num,tar,dp);
    return table(num,tar);
}
int main()
{
    vector<int> nums = {1, 2, 5};
    cout << findWays(nums, 5);
}