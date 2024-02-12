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
signed main()
{
    int n;
    cin>>n;
    vector<range> arr(n);
    for(int i =0;i<n;i++)
    {
        cin>>arr[i].a.first>>arr[i].a.second; 
    }
    sort(arr.begin(),arr.end());
    for(int i =0;i<n;i++)
    {
        
    }
//dusro ka code copy karne se khar nahi chalta bhai
}