#include <bits/stdc++.h>
using namespace std;
// unordered_map<int,int> mp;
// int solve(int *num, int n,int count, int tar,vector<int> &dp)
// {
//     if (tar == 0)
//     {   if(mp.find(count)!=mp.end())
//         {
//             return 0;
//         }
//         mp[count]++;
//         return 1;
//     }
//     if (tar < 0)
//         return 0;
    
//     if(dp[tar]!=-1) return dp[tar];
//     int inlc = 0;
//     for (int i = 0; i < n; i++)
//     {
//        inlc += solve(num, n,count+1, tar - num[i],dp);
//     }

//     return dp[tar] = inlc;
// }
long countWaysToMakeChange(int *arr, int n, int value)
{
//     vector<int> dp(value+1,-1);
//    return solve(num, n,0, value,dp);

vector<int> dp(value+1,0);
dp[0]=1;
for(int i =0;i<n;i++)
{
    for(int j = arr[i];j<dp.size();j++)
    {
        dp[j] += dp[j-arr[i]];
        int d = dp[j];
        int te=0;
    }
}
   return dp[value];
}
int main()
{
    int arr[] = {1, 2};

    cout << countWaysToMakeChange(arr, 2, 4);
}