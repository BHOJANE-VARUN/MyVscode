#include<bits/stdc++.h>
typedef long long int ll;
#define Y "YES"
#define N "NO"
#define MOD 1000000007
//const int maxsize = 1e5;
//ll arr[maxsize+1];
#define test int monu;cin>>monu;while(monu--)
using namespace std;
// void inputarrll(ll *arr,ll n)
// {   ll temp;
//     for(ll i =0;i<n;i++)
//     {
//         cin>>temp;
//         arr[i] = temp;
//     }
// }
int main()
{
test
{
       int n;
   int k,v1,v2;
   cin>>n>>k;
   vector<vector<int>> adj(n);
   for(int i=0;i<k;i++)
   {
        cin>>v1;
        cin>>v2;
        v1--;
        v2--;
        adj[v1].push_back(v2);
        adj[v2].push_back(v1);
   }
   int h1 = 0;
   for(int i=0;i<n;i++)
   {
        if(adj[i].size() > adj[h1].size())
            h1 = i;
   }
    set<int> heads;
    heads.insert(h1);
    set<int> s1;
    s1.insert(h1);
    for(const int &i: adj[h1])
    {
        s1.insert(i);
    }
   for(const int &v: adj[h1])
   {
     bool flag = false;
     for(const int &v2: adj[v])
     {
        if(s1.find(v2) == s1.end())
        {
            flag = true;
            break;
        }
     }
     if(flag)
        heads.insert(v);
   }
   vector<int> res(n,0);
   int cnt = 1;
   cout<<heads.size()<<endl;
   for(const int &head: heads )
   {
        res[head]=cnt;
        for(auto v: adj[head])
        {
            if(heads.find(v)==heads.end())
                res[v]=cnt;
        }
        cnt++;
   }
   for(int i=0;i<n;i++)
   {
    //  if(res[i]==0)
    //     cout<<1<<" ";
    // else
     cout<<res[i]<<" ";
   }
   cout<<endl;
   for(auto j:heads)
   {
       cout<<j+1<<" ";
   }
   cout<<endl;
}
//dusro ka code copy karne se khar nahi chalta bhai
}