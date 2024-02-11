#include<bits/stdc++.h>
#define int long long int
#define Y "YES"
#define N "NO"
#define MOD 1000000007
//const int maxsize = 1e5;
//int arr[maxsize+1];
#define test int monu;cin>>monu;while(monu--)
using namespace std;

int ans =0;
string str;
bool valid(int x,int y,int n)
{
    if( 0<=x && x<=n-1 && 0<=y && y<=n-1)
    {
        return true;
    }
    else{
        return false;
    }
}
void solve(int x,int y,vector<vector<bool>> &visit,int moves)
{   
    int n = 7;
    if(x==6 and y==0)
    {   if(moves==48)
        ans++;
        cout<<ans<<endl;
        return;
    }
    if(moves==48)
    {
        return;
    }
    visit[x][y]=true;
    if(y==6 and x and  !visit[x-1][y] and visit[x][y-1])
    {
        return;
    }
    if(y==0 and x and visit[x-1][y] and visit[x][y-1])
    {
        return;
    }
    if(x==0 and y and !visit[x][y-1] and visit[x+1][y])
    {
        return;
    }
    if(x==6 and y!=6 and !visit[x][y+1] and visit[x-1][y])
    {
        return;
    }
    
    if(valid(x+1,y,n) && (str[moves]=='?' or str[moves]=='D'))
    {
        solve(x+1,y,visit,moves+1);
    }
    if(valid(x,y+1,n) && (str[moves]=='?' or str[moves]=='R'))
    {
        
        solve(x,y+1,visit,moves+1);
    
    }
    if(valid(x,y-1,n) && (str[moves]=='?' or str[moves]=='L'))
    {
        if(x!=0)
        solve(x,y-1,visit,moves+1);
      
    }
    if(valid(x-1,y,n) && (str[moves]=='?' or str[moves]=='U'))
    {
        if(y!=0)
        solve(x-1,y,visit,moves+1);
       
    }
    visit[x][y]=false;
}
signed main()
{
    vector<vector<bool>> visit(7,vector<bool>(7,false));
    str = "??????R??????U??????????????????????????LD????D?";
    solve(0,1,visit,1);
    cout<<ans<<endl;
//dusro ka code copy karne se khar nahi chalta bhai
}