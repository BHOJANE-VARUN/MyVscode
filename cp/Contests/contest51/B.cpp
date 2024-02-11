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
    map<int,int> mp;
    int n;
    cin>>n;
    for(int i =0;i<n;i++)
    {
        int temp;
        cin>>temp;
        mp[temp]++;
    }
    int maxi = INT_MIN,ct =0;
    for(auto i:mp)
    {
        if(i.second>maxi)
        {
            maxi = i.second;
            ct =0;
        }
        else if(i.second==maxi)
        {
            ct++;
        }
    }
    if(ct==0) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;

 }

//dusro ka code copy karne se khar nahi chalta bhai
}