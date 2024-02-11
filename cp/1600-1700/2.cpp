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
    int n,p,k;
    cin>>n>>p>>k;
    int residue = n/k;
    int target = p%k;
    int extra = (n-1)%k;
    int ans =0;
    if(target+1<=extra)
    {
        cout<<target+1<<" "<<extra<<endl;
        ans += (target+1)*(residue+1);
        int minus = residue-(p/k);
        ans -= minus;
    }
    else{
        ans += (extra+1)*(residue+1);
        cout<<ans<<endl;
        ans += (target-extra)*(residue);
        cout<<ans<<endl;
        ans -= residue-((p/k)+1);
        cout<<ans<<endl;
    }
    cout<<ans<<endl;
}
//dusro ka code copy karne se khar nahi chalta bhai
}