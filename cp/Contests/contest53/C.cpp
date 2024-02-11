#include<bits/stdc++.h>
typedef long long int ll;
#define Y "YES"
#define N "NO"
#define MOD 1000000007
//const int maxsize = 1e5;
//ll arr[maxsize+1];
#define test int monu;cin>>monu;while(monu--)
using namespace std;
void inputarrll(ll *arr,ll n)
{   ll temp;
    for(ll i =0;i<n;i++)
    {
        cin>>temp;
        arr[i] = temp;
    }
}
int main()
{
test
{
    int n;
    cin>>n;
    ll* arr1= new ll[n];
    ll* arr2 = new ll[n];
    inputarrll(arr1,n);
    inputarrll(arr2,n);
    ll sum1=0,sum2=0;
    for(int i =0;i<n;i++)
    {
        int temp = arr1[i]-arr2[i];
        if(temp>0) sum1+= temp;
        else sum2 += temp;
    }
    if(sum1+sum2==0)
    {
        cout<<abs(sum1)<<endl;
    }
    else cout<<-1<<endl;
}
//dusro ka code copy karne se khar nahi chalta bhai
}