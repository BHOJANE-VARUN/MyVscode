#include<bits/stdc++.h>
#define int long long int
#define Y "YES"
#define N "NO"
#define MOD 1000000007
//const int maxsize = 1e5;
//int arr[maxsize+1];
#define test int monu;cin>>monu;while(monu--)
using namespace std;
void inputarrint(int *arr,int n)
{   int temp;
    for(int i =0;i<n;i++)
    {
        cin>>temp;
       arr[i] = temp;
    }
}
int solve(vector<pair<int,int>> &pairs,int lef,int rig,int i,int lefsize,int rigsize,vector<vector<vector<int>>> &dp)
{
    if(i==pairs.size())
    {
        if(lefsize!=0 and rigsize!=0)
        {
            return abs(rig-lef);
        }
        return INT_MAX;
    }
    if(dp[i][lefsize][rigsize]!=-1) return dp[i][lefsize][rigsize];

    int one = solve(pairs,max(lef,pairs[i].first),rig,i+1,lefsize+1,rigsize,dp);
    int sec = solve(pairs,max(lef,pairs[i].second),rig,i+1,lefsize+1,rigsize,dp);
    int third = solve(pairs,lef,max(rig,pairs[i].first),i+1,lefsize,rigsize+1,dp);
    int fourth = solve(pairs,lef,max(rig,pairs[i].second),i+1,lefsize,rigsize+1,dp);

    return dp[i][lefsize][rigsize] = min(one,min(sec,min(third,fourth)));
}
signed main()
{
test
{
    vector<pair<int,int>> pd;
    int n;
    cin>>n;
    vector<vector<vector<int>>> dp(n, vector<vector<int>>(n, vector<int>(n,-1)));
    for(int i=0;i<n;i++)
    {
        pair<int,int> temp;
        cin>>temp.first>>temp.second;
        pd.push_back(temp);
    }
    int lef = INT_MIN,rig = INT_MIN;
    int ans = solve(pd,lef,rig,0,0,0,dp);
    cout<<ans<<endl;
}
//dusro ka code copy karne se khar nahi chalta bhai
}