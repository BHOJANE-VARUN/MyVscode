#include <bits/stdc++.h>
using namespace std;
// bool valid(int i,int j,int n,int m)
// {
//     if(i<n && j<m) return true;
//     else return false;
// }
// int solve(vector<vector<int>> &vec,int i,int j,int index,int n,int m)
// {
//     if(!valid(i,j,n,m)) return 0;
//     if(!vec[i][j]) return 0;

//     int flag =1;
//     for(int i =0;i<index;i++)
//     {
//         if(!vec[i-1-i][j])
//         {
//             flag =0;break;
//         }
//         if(!vec[i][j-1-i])
//         {
//             flag =0;break;
//         }
//     }
//     if(flag) return 1 + solve(vec,i+1,j+1,index+1,n,m);
//     else return 0;
// }
// int maximumAreaSquare(vector<vector<int>>& MAT, int n, int m)
// {   int ans = 0;
//     for(int i =0;i<n;i++)
//     {
//         for(int j =0;j<m;j++)
//         {
//             if(MAT[i][j])
//             {
//                 int temp = 1 + solve(MAT,i+1,j+1,1,n,m);
//                 ans = max(ans,temp);
//             }
//         }
//     }
//     return ans*ans;
// }
// //recursion and memeriotion
// bool valid(int i,int j,int n,int m)
// {
//     if(i<n && j<m) return true;
//     else return false;
// }
// int solve(vector<vector<int>> &vec,int i,int j,int index,int n,int m,vector<vector<int>> &dp)
// {
//     if(!valid(i,j,n,m)) return 0;
//     if(!vec[i][j]) return 0;


//     if(dp[i][j]!=-1) return dp[i][j];
//     int flag =1;
//     for(int i =0;i<index;i++)
//     {
//         if(!vec[i-1-i][j])
//         {
//             flag =0;break;
//         }
//         if(!vec[i][j-1-i])
//         {
//             flag =0;break;
//         }
//     }
//     if (flag) {
//         dp[i][j] = 1 + solve(vec, i + 1, j + 1, index + 1, n, m,dp);
//         return dp[i][j];
//     } else
//         {dp[i][j]=0;
//             return 0;}
// }
// int maximumAreaSquare(vector<vector<int>>& MAT, int n, int m)
// {   int ans = 0;
//     vector<vector<int>> dp(n,vector<int> (m,-1));
//     for(int i =0;i<n;i++)
//     {
//         for(int j =0;j<m;j++)
//         {
//             if(MAT[i][j])
//             {
//                 int temp = 1 + solve(MAT,i+1,j+1,1,n,m,dp);
//                 ans = max(ans,temp);
//             }
//         }
//     }
//     return ans*ans;
// }
int table(vector<vector<int>> &mat,int n,int m,int &maxi)
{
    vector<vector<int>> dp(n+1,vector<int> (m+1,0));

    for(int i =n-1;i>=0;i--)
    {
        for(int j = m-1;j>=0;j--)
        {
            int right = dp[i][j+1];
            int diagonal = dp[i+1][j+1];
            int down = dp[i+1][j];
            if(mat[i][j]==1){
                dp[i][j] = 1 + min(right,min(diagonal,down));
                maxi = max(maxi,dp[i][j]);
            }
            else {
                dp[i][j]=0;
            }
        }
    }
    return 0;
}
int solve(vector<vector<int>>& mat,int i ,int j,int &maxi)
{
    if(i>=mat.size() || j>=mat[0].size()) return 0;

    int ri = solve(mat,i,j+1,maxi);
    int diag = solve(mat,i+1,j+1,maxi);
    int dowm = solve(mat,i+1,j,maxi);

    if(mat[i][j])
    {
        int ans = 1 + min(ri,min(diag,dowm));
        maxi = max(ans,maxi);
        return ans;
    }
    else{
        return 0;
    }
}
int maximumAreaSquare(vector<vector<int>>& MAT, int n, int m)
{   int ans = 0;
    //int nu = table(MAT, n, m, ans);
   int e = solve(MAT,0,0,ans);
    return ans*ans;
}
int main()
{
    vector<vector<int>> test = {{1,1},{1,1}};
    int maxi = INT_MIN;
    int null =table(test,2,2,maxi);
    cout<<maxi;
   // cout<<maximumAreaSquare(test,2,2);
}
