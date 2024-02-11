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
    int n;
    cin>>n;
    int arr[n];
    for(int i =0;i<n;i++)
    {
        int k;
        cin>>k;
        int temp =0;
        for(int j=0;j<k;j++)
        {
            
            int cur;
            cin>>cur;
            temp = (temp | (1<<cur-1));
        }
        arr[i] = temp;
    }
    for(int i =0;i<n;i++) cout<<arr[i]<<" ";
    cout<<endl;
    int f =0;
    for(int i =0;i<n;i++)
    {
        for(int j =i+1;j<n;j++)
        {
            if((arr[i] | arr[j])==31)
            {
                f=1;
                break;
            }
        }
        if(f==1) break;
    }
    if(f==1) cout<<Y<<endl;
    else cout<<N<<endl;
}
//dusro ka code copy karne se khar nahi chalta bhai
}