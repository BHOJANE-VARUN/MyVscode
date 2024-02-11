#include <bits/stdc++.h>
using namespace std;
//dp solution 
int solve(int i, int j, int m, int n,vector<vector<int>> &dp)
{
    if (i == m - 1 and j == n - 1)
    {
        return 1;
    }
    if(dp[i][j]!=-1) return dp[i][j];

    int left =0,right=0;
    if (i != m - 1)
        left = solve(i+1,j,m,n,dp);
    if(j!=n-1)
        right =solve(i,j+1,m,n,dp);
    return dp[i][j] = left+right;
}
int uniquePaths(int m, int n)
{
    int ans =0;
    vector<vector<int>> dp(m,vector<int>(n,-1));
    ans = solve(0,0,m,n,dp);
    return ans;
}
//combinatics solution
#include <bits/stdc++.h> 
int uniquePaths(int m, int n) {
            int N = n + m - 2;
            int r = m - 1; 
            double res = 1;
            
            for (int i = 1; i <= r; i++)
                res = res * (N - r + i) / i;
            return (int)res;
}
int main()
{
    cout<<uniquePaths(2,2)<<endl;
}