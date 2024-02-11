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
    int w;
    int arr[3];
    cin>>w>>arr[0]>>arr[1]>>arr[2];
    sort(arr,arr+3);
    int i = 2;
    int f=0;
    while(i>=0)
    {
        int sum = arr[i];
        int j = i-1;
        while(j>=0)
        {
            if(sum+arr[j]==w)
            {
                f=1;break;
            }
            else if(sum+arr[j]>w) {j--;continue;}
            else sum+=arr[j];
            j--;
        }
        if(f==1 or w==sum) {cout<<Y<<endl;
        f=1;
        break;
        }
        i--;
    }
    if(f==0)  cout<<N<<endl;
 }

//dusro ka code copy karne se khar nahi chalta bhai
}