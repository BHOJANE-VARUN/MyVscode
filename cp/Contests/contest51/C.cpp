#include<bits/stdc++.h>
typedef long long int ll;
#define Y "YES"
#define N "NO"
#define MOD 1000000007
const int maxsize = 1e5;
ll arr[40];
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
    int i =1;
    arr[0]=1;
    while(i<40)
    {
        arr[i] = arr[i-1]*2*1ll;
        i++;
    }
test
 {
     int n;
     cin>>n;
     int ct =-1;
     while (n>0)
     {
        int i = 39;
        while(n-arr[i]<0) i--;
        n -= arr[i];
        ct++;
     }
     cout<<ct<<endl;
 }

//dusro ka code copy karne se khar nahi chalta bhai
}