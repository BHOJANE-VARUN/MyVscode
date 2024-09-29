#include<bits/stdc++.h>
#define yes cout<<"YES"<<endl;
#define no cout<<"NO"<<endl
#define MOD 1000000007
const int maxsize = 2*(1e5);
int vis[maxsize+1];
#define test int monu;cin>>monu;while(monu--)
using namespace std;
bool comp(pair<int,int> &a,pair<int,int>&b)
{
    if(a.second<b.second) return true;
    else return false;
}
signed main()
{
    int n,k;cin>>n>>k;
    vector<pair<int,int>> arr;
    for(int i=0;i<n;i++)
    {
        pair<int,int> p;cin>>p.first>>p.second;
        arr.push_back(p);
    }
    sort(arr.begin(),arr.end(),comp);
//     int cur =0;
//     int j =0;
//     int ans =0;
//     int i =1;
    // cout<<endl;
    // for(auto i:arr)
    // {
    //     cout<<i.first<<" "<<i.second<<endl;
    // }
    // cout<<endl;
    // while(i<=maxsize and j<arr.size())
    // {
    //     cur += vis[i];
    //     if(arr[j].second<i)
    //     {
    //         j++;
    //     }
    //     else if(arr[j].first<=i and cur<k)
    //     {
    //         vis[arr[j].second] += -1;
    //         cur++;
    //         ans++;
    //         j++;
    //     }
    //     else
    //     {
    //         i++;
    //     }
            
    //    // cout<<cur<<" ";
    // }
    // cout<<endl;
    // for(int i =1;i<=11;i++) cout<<vis[i]<<" ";
    // cout<<endl;
    set<pair<int,int>> s;
    int ans=0;
    for(int i =0;i<n;i++)
    {
        if(s.size()==0)
        {
            s.insert({arr[i].second*-1,i});
        }
        else
        {
            auto it = s.lower_bound({(arr[i].first*-1),-1});
            if(it!=s.end())
            {
                s.erase(it);
                s.insert({arr[i].second*-1,i});
            }
            else{
                if(s.size()<k)
                {
                    s.insert({arr[i].second*-1,i});
                }
                else ans++;
            }
        }
    }
    //cout<<endl;
     cout<<n-ans<<endl;
//dusro ka code copy karne se ghar nahi chalta bhai
}
