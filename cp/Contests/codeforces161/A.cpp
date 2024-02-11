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
    int n;
    cin>>n;
    string a,b,c;
    cin>>a>>b>>c;
    int f =0;
    for(int i =0;i<n;i++)
    {
        if(a[i]!=c[i] or b[i]!=c[i])
        {
            f =1;
        }
    }
    if(f) cout<<Y<<endl;
    else cout<<N<<endl;
}
//dusro ka code copy karne se khar nahi chalta bhai
}