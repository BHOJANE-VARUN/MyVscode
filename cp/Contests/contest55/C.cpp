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
    unordered_map<int,int> mp;
    int n;cin>>n;
    vector<int> vec;
    for(int i =0;i<n;i++)
    {
        int temp;
        cin>>temp;
        mp[temp]++;
        vec.push_back(temp);
    }
    int k;cin>>k;
    for(int i =0;i<k;i++)
    {
        int temp;
        cin>>temp;
        mp[temp]++;
    }
    for(auto i:vec)
    {
        if(mp[i]==1) cout<<i<<" ";
    }
    cout<<endl;
}
//dusro ka code copy karne se khar nahi chalta bhai
}