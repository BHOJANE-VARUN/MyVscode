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
{   int temp;
    for(int i =0;i<n;i++)
    {
        cin>>temp;
       arr[i] = temp;
    }
}
signed main()
{
test
{
    int a,b;
    cin>>a>>b;//3 2 
    int ans = max(a,b)*max(a,b);
    if(a>b)
    {
        if(a%2)
        {
            ans -= (a-1);       
            ans -= (a-b);
        }
        else{
            ans -= (b-1);
        }
    }
    else{
        if(b%2)
        {
            ans -= (a-1);
        }
        else{
            ans -= (b-1);
            ans -= (b-a);
        }
    }
    cout<<ans<<endl;
}
//dusro ka code copy karne se khar nahi chalta bhai
}   