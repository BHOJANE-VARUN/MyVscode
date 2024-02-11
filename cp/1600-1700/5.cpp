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
{   
}
signed main()
{
test
{
    int n,w,r;
    cin>>n>>w>>r;
    unordered_map<int,int> mp;
    int temp;
    for(int i =0;i<n;i++)
    {
      cin>>temp;
      mp[temp]++;
    }
    int sum = 0;
    for(auto i:mp)
    {
        if(i.second>1)
        {
            sum += 2*i.first*(i.second/2);
        }
    }
    sum += r;
    if(sum>=w) cout<<Y<<endl;
    else cout<<N<<endl;
}
//dusro ka code copy karne se khar nahi chalta bhai
}