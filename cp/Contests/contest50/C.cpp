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
    int n,x;
    cin>>n>>x;
    if(x<n) {cout<<-1<<endl;continue;}
    cout<<x-n+1<<" ";
    for(int i =1;i<=n;i++)
    {
        if(i==x-n+1)continue;
        cout<<i<<" ";
    }
    cout<<endl;
 }

//dusro ka code copy karne se khar nahi chalta bhai
}