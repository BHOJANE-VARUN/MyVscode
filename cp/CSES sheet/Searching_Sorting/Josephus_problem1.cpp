#include<bits/stdc++.h>
#define int long long int
#define Y "YES"
#define N "NO"
#define MOD 1000000007
//const int maxsize = 1e5;
//int arr[maxsize+1];
#define test int monu;cin>>monu;while(monu--)
using namespace std;
void solve(int i,int &f,vector<bool> &visit,int n,int timer,int k)
{   
    if(timer==n*20) return;
    if(visit[i])
    {
        solve((i+1)%(n+1),f,visit,n,timer+1,k);
        return;
    }
    if(f!=0)
    {   f = (f+1)%(k+1);
        solve((i+1)%(n+1),f,visit,n,timer,k);
        return;
    }
    visit[i] = true;
    cout<<i<<" ";
    f = 1;
    solve((i+1)%(n+1),f,visit,n,timer,k);
    return;
}
signed main()
{
    int n,k;
    cin>>n>>k;
    k = k%n;
    if(n==1)
    {
        cout<<1;
        return 0;
    }
    vector<bool> visit(n+1,false);
    int ct =0;
    visit[0] = true;
    solve(k+1,ct,visit,n,0,k);
    // for(int i =1;i<=n;i++)
    // {
    //     if(!visit[i])
    //     {
    //         ct = (ct+1)%2;
            
    //         if(ct==0)
    //         {cout<<i<<" ";visit[i] = true;}
    //     }     
    // }
    // for(int i =1;i<=n;i++)
    // {
    //     if(!visit[i])
    //     {
    //         ct = (ct+1)%2;
    //         if(ct==0)
    //         {cout<<i<<" ";visit[i] = true;}
    //     } 
    // }
    // for(int i =1;i<=n;i++)
    // {
    //     if(!visit[i])
    //     {
    //         ct = (ct+1)%2;
    //         if(ct==0)
    //         {cout<<i<<" ";visit[i] = true;}
    //     } 
    // }
    // for(int i =1;i<=n;i++) 
    //     if(!visit[i])
    //         cout<<i<<" ";
    
//dusro ka code copy karne se khar nahi chalta bhai
}