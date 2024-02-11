#include <bits/stdc++.h> 
using namespace std;
bool valid(int x,int y,int n,int m)
{
    if( 0<=x && x<=n-1 && 0<=y && y<=m-1)
    {
        return true;
    }
    else{
        return false;
    }
}
void solve(int n,int m,vector<string> &grid,string &s,int &ans,int index,int x,int y)
{    
    if(index==s.length())
    {
        ans++;
        return ;
    }


    if((valid(x+1,y,n,m) && grid[x+1][y]==s[index]))
    {
        grid[x+1][y]=0;
        solve(n,m,grid,s,ans,index+1,x+1,y);
        grid[x+1][y]=s[index];

    }
    char ch = grid[x][y+1];
    if((valid(x,y+1,n,m) && grid[x][y+1]==s[index]))
    {
       
        grid[x][y+1]=0;
        solve(n,m,grid,s,ans,index+1,x,y+1);
        grid[x][y+1]=s[index];

    }
    if((valid(x,y-1,n,m) && grid[x][y-1]==s[index]))
    {
        grid[x][y-1]=0;
        solve(n,m,grid,s,ans,index+1,x,y-1); 
        grid[x][y-1]=s[index];     
    }
    if((valid(x-1,y,n,m) && grid[x-1][y]==s[index]))
    {
        
        grid[x-1][y]=0;
        solve(n,m,grid,s,ans,index+1,x-1,y);
        grid[x-1][y]=s[index];      

    }
}
int countStrings(int n, int m, vector<string> &grid , string &s)
{   int ans =0;
    for (int i = 0; i < n; i++)
    {
        for(int j = 0;j<m;j++)
        {   if(grid[i][j]==s[0])
            {grid[i][j]=0;
            solve(n,m,grid,s,ans,1,i,j);
            grid[i][j]=s[0];
            }
        }
    }
    return ans;
	
}
int main()
{
    vector<string> grid = {"ninjas","opikat"};
    string s = "ninjas";
    int ans = countStrings(grid.size(),grid[0].size(),grid,s);
    cout<<ans;
}
