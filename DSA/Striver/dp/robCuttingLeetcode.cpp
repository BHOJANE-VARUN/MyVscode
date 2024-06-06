#include<bits/stdc++.h>
#define int long long int
#define yes cout<<"YES"<<endl;
#define no cout<<"NO"<<endl
#define MOD 1000000007
//const int maxsize = 1e5;
//int arr[maxsize+1];
#define test int monu;cin>>monu;while(monu--)

using namespace std;

class Solution {
public:
    int solve(int s,int e,vector<int>&arr,vector<vector<int>> &dp)
    {
        if(e-s<2)
            return 0;
        if(s>e)
            return 10000000;
        if(dp[s][e]!=-1)
            return dp[s][e];
        int ans = 10000000;
        for(int i =s+1;i<e;i++)
        {
            int lef = solve(s,i,arr,dp);
            int rig = solve(i,e,arr,dp);
            int cur = lef+rig+(arr[e]-arr[s]);
            ans = min(ans,cur);
        }
        return dp[s][e] =  (ans==10000000?0:ans);
    }
    int table(int n,vector<int>&cuts)
    {
        vector<vector<int>> dp(cuts+3,vector<int>(cuts+3,0));
        cuts.push_back(0);
        cuts.push_back(n);
        sort(cuts.begin(),cuts.end());
        for(int i =3;i<cuts.size();i++)
        {
            for(int j =0;j<cuts.size()-i;j++)
            {
                int ans = 100000;
                for(int k = j+1;k<j+i-1;k++)
                {
                   int cur = dp[k-j+1][j] + dp[j+i-k+1][k] + i;
                   ans = min(ans,cur);
                }
                dp[i][j] = ans;
            }
        }
        return dp[cuts.size()-1][0];
    }
    int minCost(int n, vector<int>& cuts) {
        // vector<vector<int>> dp(cuts+3,vector<int>(cuts+3,-1));
        // cuts.push_back(0);
        // cuts.push_back(n);
        // sort(cuts.begin(),cuts.end());
        return table(n,cuts);
    }
};
