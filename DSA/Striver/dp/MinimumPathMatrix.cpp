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
    int solve(int i,int j,vector<vector<int>> &grid,vector<vector<int>> &dp)
    {
        if(i>=grid.size() or j>=grid[0].size() or i<0 or j<0)
            return 1000000;
        if(i==grid.size()-1 and j==grid[0].size()-1)
            return grid[grid.size()-1][grid[0].size()-1];
        if(dp[i][j]!=-1)
            return dp[i][j];
        int rig = solve(i,j+1,grid,dp);
        int dow = solve(i+1,j,grid,dp);
        return dp[i][j] =  min(rig,dow)+grid[i][j];
    }
    int table(vector<vector<int>>& grid)
    {
        vector<vector<int>> dp(grid.size()+1,vector<int> (grid[0].size()+1,0));
        dp[grid.size()-1][grid[0].size()-1] = grid[grid.size()-1][grid[0].size()-1];

        for(int i = grid.size()-1;i>=0;i--)
        {
            for(int j = grid[0].size()-1;j>=0;j--)
            {
                int dow = dp[i+1][j],rig = dp[i][j+1];
                if(j+1==grid[0].size())
                    rig = 100000;
                if(i+1==grid.size())
                    dow = 100000;
                int ans = min(rig,dow);
                if(ans==100000)
                    ans =0;
                dp[i][j] = ans + grid[i][j];
            }
        }
        return dp[0][0];
    }
    int minPathSum(vector<vector<int>>& grid) {
        //vector<vector<int>> dp(grid.size()+1,vector<int> (grid[0].size()+1,-1));
        return table(grid);
    }
};