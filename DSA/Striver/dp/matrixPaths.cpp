#include <bits/stdc++.h>
#define int long long int
#define yes cout << "YES" << endl;
#define no cout << "NO" << endl
#define MOD 1000000007
// const int maxsize = 1e5;
// int arr[maxsize+1];
#define test     \
    int monu;    \
    cin >> monu; \
    while (monu--)
using namespace std;
#include <bits/stdc++.h> 
int solve(int i,int j,vector<vector<int>> &grid,vector<vector<int>> &dp)
{
    if(i==grid.size()-1 and j==grid[0].size()-1)
        return 0;
    
    if(dp[i][j]!=-1) return dp[i][j];

    int dow =INT_MAX;
    int rig = dow;
    if(i+1<grid.size())
        dow = solve(i+1,j,grid,dp);
    if(j+1<grid[0].size())
        rig = solve(i,j+1,grid,dp);
    //cout<<i<<" "<<j<<' ';
   // cout<<dow<<' '<<rig<<endl;
    return dp[i][j] =  grid[i][j] + min(dow,rig);
}
int table(vector<vector<int>> &grid)
{
    vector<vector<int>> dp(grid.size()+1,vector<int> (grid[0].size()+1,0));
    dp[1][1] = grid[0][0];
    for(int i =1;i<=grid.size();i++)
    {
        for(int j = 1;j<=grid[0].size();j++)
        {
            if(i==1 and j==1)
                continue;
            int dow =INT_MAX;
            int rig = dow;
            if(i-1>0)
                    dow = dp[i-1][j];
            if(j-1>0)
                    rig = dp[i][j-1];
            dp[i][j] = grid[i-1][j-1]+ min(dow,rig);
        }
    }
    return  dp[grid.size()][grid[0].size()];
}
int tableopti(vector<vector<int>> &grid)
{
    vector<int> prev(grid[0].size()+1,0),cur(grid[0].size()+1,0);
    cur[1] = grid[0][0];
    for(int i =1;i<=grid.size();i++)
    {
        for(int j = 1;j<=grid[0].size();j++)
        {
            if(i==1 and j==1)
                continue;
            int dow =INT_MAX;
            int rig = dow;
            if(i-1>0)
                    dow = prev[j];
            if(j-1>0)
                    rig = cur[j-1];
            cur[j] = grid[i-1][j-1]+ min(dow,rig);
        }
        prev = cur;
    }
    return  prev[grid[0].size()];
}
int minSumPath(vector<vector<int>> &grid) {
    // vector<vector<int>> dp(grid.size()+1,vector<int> (grid[0].size()+1,-1));
    // return grid[grid.size()-1][grid[0].size()-1] +  solve(0,0,grid,dp);
    return tableopti(grid);
}
signed main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cout << matrixMultiplication(arr, n) << endl;
    // dusro ka code copy karne se ghar nahi chalta bhai
}