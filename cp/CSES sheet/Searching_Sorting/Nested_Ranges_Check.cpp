#include<bits/stdc++.h>
#define int long long int
#define Y "YES"
#define N "NO"
#define MOD 1000000007
//const int maxsize = 1e5;
//int arr[maxsize+1];
#define test int monu;cin>>monu;while(monu--)
using namespace std;
struct range
{
    pair<int,int> a;
    int index;
    bool operator <(range &b)
    {
        if(a.first==b.a.first)
            return a.second>b.a.second;
        return a.first<b.a.first;
    }
};

bool contain(pair<int,int> &a,pair<int,int> &b)
{
    return (a.first<=b.first and a.second>=b.second);
}
signed main()
{
    int n;
    cin>>n;
    vector<range> arr;
    for(int i =0;i<n;i++)
    {
        pair<int,int> temp;
        cin>>temp.first>>temp.second;
        range cur;
        cur.a = temp;
        cur.index = i;
        arr.push_back(cur);
    }
    sort(arr.begin(),arr.end());
    vector<bool> arr1(n,0);
    vector<bool> arr2(n,0);
    int maxi = 0; 
    for(int i =0;i<n;i++)
    {
        if(arr[i].a.second<=maxi)
        {
            arr2[arr[i].index] = 1;  
        }
        maxi = max(maxi,arr[i].a.second);
    }
    int mini = INT_MAX;
    for(int i =n-1;i>=0;i--)
    {
        if(arr[i].a.second>=mini)
        {
            arr1[arr[i].index] = 1;  
        }
        mini = min(mini,arr[i].a.second);
    }
    for(auto i:arr1) cout<<i<<" ";
    cout<<endl;
    for(auto i:arr2) cout<<i<<" ";
    cout<<endl;
//dusro ka code copy karne se khar nahi chalta bhai
}