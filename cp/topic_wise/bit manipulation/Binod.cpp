#include<bits/stdc++.h>
#define int long long int
#define Y "YES"
#define N "NO"
#define MOD 1000000007
//const int maxsize = 1e5;
//int arr[maxsize+1];
#define test int monu;cin>>monu;while(monu--)
using namespace std;
signed main()
{
test
{
    int n,q;
    cin>>n>>q;
    int *arr = new int[n];
    for(int i =0;i<n;i++)
    {
      cin>>arr[i];
    }
    vector<vector<int>> mt;
    int temp =1;
    for(int i =0;i<60;i++)
    {
        vector<int> cur;
        cur.push_back(0);
        for(int k =0;k<n;k++)
        {
            if(((temp<<i)&arr[k])>0)
            {
                cur.push_back(cur[k]+1);
            }
            else{
                cur.push_back(cur[k]);
            }
        }
        mt.push_back(cur);
    }
    // for(auto i:mt) {
        // for(auto j:i) cout<<j<<" ";
        // cout<<endl;
    // }
    
    while(q--)
    {
        int k,l1,l2,r1,r2;
        cin>>k>>l1>>r1>>l2>>r2;
        // for(auto j:mt[k]) cout<<j<<" ";
        // cout<<endl;
        int noset = mt[k][r1]-mt[k][l1-1];
        int noset2 = mt[k][r2]-mt[k][l2-1];
        //cout<<ct1<<" "<<ct2<<endl;
        int noele = r1-l1+1,noele2 = r2-l2+1;
        int ct10 = noele-noset;
        int ct20 = noele2-noset2;
       cout<<(noset*ct20)+(noset2*ct10)<<endl;
    }
}
//dusro ka code copy karne se khar nahi chalta bhai
}