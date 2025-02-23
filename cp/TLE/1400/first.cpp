#include<bits/stdc++.h>
#define int long long int
#define yes cout<<"YES"<<endl;
#define no cout<<"NO"<<endl
#define MOD 1000000007
//const int maxsize = 1e5;
//int arr[maxsize+1];

#define test int monu;cin>>monu;while(monu--)
using namespace std;
pair<int,int> count(int n)
{
    int zero =0;
    int one =0;
    while(n%10==0)
    {
        zero++;
        n = n/10;
    }
    while(n)
    {
        one++;
        n = n/10;
    }
    return make_pair(zero,one);
}
signed main()
{
test
{
    int n,m;
    cin>>n>>m;
    int *arr = new int[n];
    for(int i =0;i<n;i++)
    {
      cin>>arr[i];
    }
    vector<pair<int,int>> pq;
    int ans =0;
    for(int i=0;i<n;i++)
    {
        pair<int,int> temp = count(arr[i]);
        ans += temp.second;
        pq.push_back(temp);
    }
    // for(auto i:pq)
    // cout<<i.first<<" "<<i.second<<endl;
    // cout<<ans<<endl;
    sort(pq.begin(),pq.end());
    if(ans>m)
    {
        cout<<"Sasha"<<endl;
        continue;
    }
    else{
        int i = pq.size()-1;
        int f=0;
        int cur =0;
        while(i>=0)
        {
            // cout<<pq[0].first<<" "<<pq[0].second<<endl;
            // cout<<pq[i].first<<" "<<pq[i].second<<endl;
            if(f==0)
            {
                pq[i].first = 0;
                cur += pq[i].second;
                f =1;
                i--;
            }
            else if(f==1)
            {
                cur += pq[i].first + pq[i].second;
                f = 0;
                i--;
            }
        }
        // 10 10 10 10
        // 1  1010 10
        // 1 1010 1
        // 10101 1
        
        if(cur>m)
        {
            cout<<"Sasha"<<endl;
        }
        else{
            cout<<"Anna"<<endl;
        }
    }
}
//dusro ka code copy karne se ghar nahi chalta bhai
}